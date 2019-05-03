if not exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[SB_Categories]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
 BEGIN
CREATE TABLE [dbo].[SB_Categories] (
    [Code] [varchar] (10) NOT NULL,
    [Description] [varchar] (128) NULL CONSTRAINT DF_Categories_Descriptio_00 DEFAULT ('')
   CONSTRAINT [PK_Categories] PRIMARY KEY NONCLUSTERED 
    (
        [Code]
    ) ON [PRIMARY]
) ON [PRIMARY]

END
GO
