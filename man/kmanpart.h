/*  This file is part of the KDE project
    Copyright (C) 2002 Alexander Neundorf <neundorf@kde.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/


#ifndef KMANPART_H
#define KMANPART_H

class QByteArray;

#include <QObject>

#include <kparts/part.h>
#include <kparts/browserextension.h>
#include <khtml_part.h>
#include <kio/job.h>
#include <kio/jobclasses.h>

/**
 * Man Page Viewer
 * This is needed so that we can open local files using the man: protocol transparently.
 * Testcase: click on a man page file (e.g. makekdewidgets.1) in konqueror.
 */
class KManPart : public KHTMLPart
{
   Q_OBJECT
   public:
      KManPart( QWidget * parent, QObject*, const QVariantList& );
      KParts::BrowserExtension * extension() {return m_extension;}

   public Q_SLOTS:
      bool openUrl( const QUrl &url ) override;
   protected Q_SLOTS:
      void readData(KIO::Job * , const QByteArray & data);
      void jobDone( KJob *);
   protected:
      bool openFile() override;
      KParts::BrowserExtension * m_extension;
      KIO::TransferJob *m_job;
};

#endif

