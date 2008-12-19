/*
 * Copyright (c) 2007 Henrique Pinto <henrique.pinto@kdemail.net>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES ( INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION ) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * ( INCLUDING NEGLIGENCE OR OTHERWISE ) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef LIBARCHIVEHANDLER_H
#define LIBARCHIVEHANDLER_H

#include "kerfuffle/archiveinterface.h"

using namespace Kerfuffle;

class LibArchiveInterface: public ReadWriteArchiveInterface
{
	Q_OBJECT
	public:
		explicit LibArchiveInterface( const QString & filename, QObject *parent = 0 );
		~LibArchiveInterface();

		bool list();
		bool copyFiles( const QList<QVariant> & files, const QString & destinationDirectory, Archive::CopyFlags flags );

		bool addFiles( const QStringList & files, const CompressionOptions& options );
		bool deleteFiles( const QList<QVariant> & files );

	private:
		int extractionFlags() const;
		void copyData( struct archive *source, struct archive *dest, bool partialprogress = true );
		void copyData( QString filename, struct archive *dest, bool partialprogress = true );
		void emitEntryFromArchiveEntry(struct archive_entry *entry);
		void writeFile(const QString& fileName, struct archive* arch, struct archive_entry* entry);


		int cachedArchiveEntryCount;
		qlonglong extractedFilesSize;
		qlonglong currentExtractedFilesSize;
		bool overwriteAll;
		bool m_emitNoEntries;
		QStringList m_writtenFiles;
};

#endif // LIBARCHIVEHANDLER_H
