/*
    This file is part of the Mollet network library, part of the KDE project.

    Copyright 2009 Friedrich W. H. Kossebau <kossebau@kde.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) version 3, or any
    later version accepted by the membership of KDE e.V. (or its
    successor approved by the membership of KDE e.V.), which shall
    act as a proxy defined in Section 6 of version 3 of the license.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library. If not, see <http://www.gnu.org/licenses/>.
*/

#include "netdevice_p.h"

// library
#include "netservice_p.h"
// Qt
#include <QMutableListIterator>


namespace Mollet
{

NetDevicePrivate::NetDevicePrivate( const QString& name )
  : mName( name )
  , mType( NetDevice::Unknown )
{
}

bool NetDevicePrivate::hasService( const QString& id ) const
{
    bool result = false;

    foreach( const NetService& service, mServiceList )
    {
        const NetServicePrivate* const d = service.dPtr();
        if( d->id() == id )
        {
            result = true;
            break;
        }
    }

    return result;
}

NetService NetDevicePrivate::removeService( const QString& id )
{
    NetService result;
    QMutableListIterator<NetService> it( mServiceList );
    while( it.hasNext())
    {
        const NetService& service = it.next();
        const NetServicePrivate* const d = service.dPtr();
        if( d->id() == id )
        {
            result = service;
            it.remove();
            break;
        }
    }
    return result;
}

NetDevicePrivate::~NetDevicePrivate()
{
}

}
