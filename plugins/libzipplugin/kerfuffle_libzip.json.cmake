{
    "KPlugin": {
        "Description": "Full support for the zip archive format", 
        "Description[ca@valencia]": "Implementació completa del format d'arxiu ZIP", 
        "Description[ca]": "Implementació completa del format d'arxiu ZIP", 
        "Description[es]": "Uso total del formato de archivo comprimido zip", 
        "Description[nl]": "Volledige ondersteuning voor het zip-archiefformaat", 
        "Description[pt]": "Suporte total para o formato de pacotes ZIP", 
        "Description[sv]": "Fullt stöd för arkivformatet zip", 
        "Description[uk]": "Повноцінна підтримка архівів у форматі zip", 
        "Description[x-test]": "xxFull support for the zip archive formatxx", 
        "Id": "kerfuffle_libzip", 
        "MimeTypes": [
            "@SUPPORTED_MIMETYPES@"
        ], 
        "Name": "Libzip plugin", 
        "Name[ca@valencia]": "Connector del Libzip", 
        "Name[ca]": "Connector del Libzip", 
        "Name[es]": "Complemento Libzip", 
        "Name[nl]": "Libzip-plug-in", 
        "Name[pt]": "'Plugin' da Libzip", 
        "Name[sv]": "Libzip-insticksprogram", 
        "Name[uk]": "Додаток libzip", 
        "Name[x-test]": "xxLibzip pluginxx", 
        "ServiceTypes": [
            "Kerfuffle/Plugin"
        ], 
        "Version": "@KDE_APPLICATIONS_VERSION@"
    }, 
    "X-KDE-Kerfuffle-ReadWrite": true, 
    "X-KDE-Priority": 200, 
    "application/zip": {
        "Encryption": true, 
        "EncryptionMethodDefault": "AES256", 
        "EncryptionMethods": [
            "AES256", 
            "AES192", 
            "AES128"
        ], 
        "SupportsTesting": true, 
        "SupportsWriteComment": true
    }
}
