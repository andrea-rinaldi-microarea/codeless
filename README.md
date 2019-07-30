# EDI Helpers
Set of helper components to compose or interpret EDI messages.

# Export
Basic usage schema:
``` c#
var process = ProcessHelpers.Load(/* json Process definition */);
var message = MessageHelpers.Load(/* json Message definition */);

using (Composer composer = new Composer(message, process.composition, new /* IXMLProvider */, new /* IEnvironmentProvider */, new /* ICustomExtractor */))  
{
    TextWriter stream = new StreamWriter(*/somewhere*/); 

    composer.Compose(stream);                
};
```
`ProcessHelpers.Load(string)`: receive a json string containing a `Process` definition; returns a `Process` instance.

`MessageHelpers.Load(string)`: receive a json string containing a `Message` definition; returns a `Message` instance. _TIP: the `Process` contains the name of the `Message`_

`Composer(Message, Composition, IXMLProvider, IEnvironmentProvider, ICustomExtractor)` create an instance of a `Composer` object, capable of composing a `Message`, following the `Composition` rules, from the XDocument returned by an `IXMLProvider`.
* `Message`: the definition of the message to compose  
* `Composition`: the composition rules, contained in the `Process` definition  
* `IXMLProvider`: a class implementing the `IXMLProvider` interface returning all the XML XDocuments needed to compose the message
* `IEnvironmentProvider`: a class implementing the `IEnvironmentProvider` interface, providing all the `environment` rules 
* `ICustomExtractor`: a class implementing the `ICustomExtractor` interface, providing the extraction logic for rules of `custom` type.

`Composer.compose(TextWriter)`: compose the message, returning it in the `TextWriter` parameter.

# Import
Basic usage schema:
``` c#
var process = ProcessHelpers.Load(/* json Process definition */);
var message = MessageHelpers.Load(/* json Message definition */);

using (XMLComposer composer = new XMLComposer(message, process.composition, new /* IXSDProvider */, new /* ICustomInterpreter */))
{
    TextReader stream = new StreamReader(/*somewhere*/); 
    foreach (var xDoc in composer.Compose(stream))
    {
        xDoc.Save(/*somewhere*/);
    } 
}

```
`ProcessHelpers.Load(string)`: receive a json string containing a `Process` definition; returns a `Process` instance.

`MessageHelpers.Load(string)`: receive a json string containing a `Message` definition; returns a `Message` instance. _TIP: the `Process` contains the name of the `Message`_

`XMLComposer(Message, Composition, IXSDProvider, ICustomInterpreter)` create an instance of a `XMLComposer` object, capable of composing a collection of XML documents having the schema returned by an `IXSDProvider`, interpreting the `Message`, according to the `Composition` rules.
* `Message`: the definition of the message to interpret  
* `Composition`: the composition rules, contained in the `Process` definition  
* `IXSDProvider`: a class implementing the `IXSDProvider` interface returning the schema of the XML XDocuments to compose
* `ICustomInterpreter`: a class implementing the `ICustomInterpreter` interface, providing the interpretation logic for rules of `custom` type.

`XMLComposer.compose(TextReader)`: interprets the message read from the `TextReader` parameter, yielding a collection of `XDocuments`.

# Import with manual composition
In some cases the XML Schema may be not available, so it is possible to manually compose the XML still using the flat file intepretation component.  
The component to use is the `XMLComposerManual`.  
Basic usage schema:
``` c#
var process = ProcessHelpers.Load(/* json Process definition */);
var message = MessageHelpers.Load(/* json Message definition */);

var interpreter = new Interpreter(message);
using (var composer = new XMLComposerManual(process.composition, interpreter, new /* ICustomInterpreter */))
{
    TextReader stream = new StreamReader(/*somewhere*/); 
    interpreter.Start(stream);
    foreach (var more in interpreter.Messages())
    {
        XElement root;
        string rootPath;
        var xDoc = composer.CreateDocument(/* root tag */, out rootPath, out root);
        ...
        string nodePath;
        var node = composer.AddNode(/* node tag*/, root, rootPath, out nodePath);
        composer.AddField(node, nodePath, /* field tag */, typeof(/* node type */));
        ...
        foreach (var l in interpreter.MessageDetail())
        {
            ...
        }
        ...

        xDoc.Save(/*somewhere*/);
    } 
}
```
`XMLComposerManual.CreateDocument`: create an empty XML document with just the root element.

`XMLComposerManual.AddNode`: add an empty node to the one passed as parameter, returns its XPath.

`XMLComposerManual.AddField`: add a field node, that is a node containing a value. The value is retrieved according to the `composition` and the XPath of the new node. 
