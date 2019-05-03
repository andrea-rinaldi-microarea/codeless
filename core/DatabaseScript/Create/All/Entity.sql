IF NOT EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[Entity]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1)
BEGIN
CREATE TABLE [dbo].[Entity] (
    [DocID] [int] NOT NULL ,
    [DocNo] [varchar] (10) NULL CONSTRAINT DF_Entity_DocNo_00 DEFAULT (''),
    [DocDate] [datetime] NULL CONSTRAINT DF_Entity_DocDate_00  DEFAULT('17991231'),
	[LastSubId] [int] NULL CONSTRAINT DF_Entity_LastSubId_00 DEFAULT(0),
    CONSTRAINT [PK_Entity] PRIMARY KEY NONCLUSTERED
    (
     [DocID]
    ) ON [PRIMARY]
) ON [PRIMARY]

END
GO


IF NOT EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[EntityDetails]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1)
BEGIN
CREATE TABLE [dbo].[EntityDetails] (
    [DocID] [int] NOT NULL ,
    [DocSubID] [int] NOT NULL ,
    [Code] [varchar] (12) NULL CONSTRAINT DF_Entity_Code_00 DEFAULT(''),
    [Description] [varchar] (128) NULL CONSTRAINT DF_Entity_Descriptio_00 DEFAULT (''),
    CONSTRAINT [PK_EntityDetails] PRIMARY KEY NONCLUSTERED
    (
     [DocID],
     [DocSubID]
    ) ON [PRIMARY]
) ON [PRIMARY]

END
GO

