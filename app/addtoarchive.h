/*
 * ark -- archiver for the KDE project
 *
 * Copyright (C) 2008 Harald Hvaal <haraldhv (at@at) stud.ntnu.no>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#ifndef ADDTOARCHIVE_H
#define ADDTOARCHIVE_H

#include <KParts/MainWindow>
#include <KParts/ReadWritePart>
#include <KUrl>
#include <KDialog>
#include "kerfuffle/jobs.h"
#include "kerfuffle/archive.h"
#include "kerfuffle/queries.h"

using Kerfuffle::Query;

class Interface;
class KJobTrackerInterface;

class AddToArchive : public QObject
{
	Q_OBJECT

	public:
		AddToArchive( QObject *parent = 0 );
		~AddToArchive();

		bool showAddDialog();
		void setPreservePaths(bool value);
		void setChangeToFirstPath(bool value) { m_changeToFirstPath = value; }

	public slots:
		bool addInput( const KUrl& url);
		void setFilename( const KUrl& path ) { m_filename = path.path(); }
		void setAutoFilenameSuffix( const QString& suffix ) { m_autoFilenameSuffix = suffix; }
		bool startAdding();

	private:
		QString m_filename;
		QString m_strippedPath;
		QString m_autoFilenameSuffix;
		QString m_firstPath;
		QStringList m_inputs;
		bool m_changeToFirstPath;

};

#endif // ADDTOARCHIVE_H
