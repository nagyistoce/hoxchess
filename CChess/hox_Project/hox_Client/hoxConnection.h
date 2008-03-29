/***************************************************************************
 *  Copyright 2007, 2008 Huy Phan  <huyphan@playxiangqi.com>               *
 *                                                                         * 
 *  This file is part of HOXChess.                                         *
 *                                                                         *
 *  HOXChess is free software: you can redistribute it and/or modify       *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation, either version 3 of the License, or      *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  HOXChess is distributed in the hope that it will be useful,            *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with HOXChess.  If not, see <http://www.gnu.org/licenses/>.      *
 ***************************************************************************/

/////////////////////////////////////////////////////////////////////////////
// Name:            hoxConnection.h
// Created:         11/05/2007
//
// Description:     The Connection which is the base for all connections.
/////////////////////////////////////////////////////////////////////////////

#ifndef __INCLUDED_HOX_CONNECTION_H_
#define __INCLUDED_HOX_CONNECTION_H_

#include <wx/wx.h>
#include "hoxEnums.h"
#include "hoxTypes.h"

/* Forward declarations */
class hoxPlayer;

// ----------------------------------------------------------------------------
// hoxConnection
// ----------------------------------------------------------------------------

/**
 * The interface for a Connection providing the communication between a player
 * and a remote server.
 * The class is the base class for all other Connections.
 */
class hoxConnection : public wxObject
{
public:
    hoxConnection( hoxPlayer* player = NULL );
    virtual ~hoxConnection();

    virtual void Start() = 0;
    virtual void Shutdown() = 0;
    virtual bool AddRequest( hoxRequest* request ) = 0;
    virtual bool IsConnected() const = 0;

protected:
    hoxPlayer* GetPlayer() const  { return m_player; }

private:
    hoxPlayer*         m_player;
                /* The player that owns this connection */

    DECLARE_ABSTRACT_CLASS(hoxConnection)
};

#endif /* __INCLUDED_HOX_CONNECTION_H_ */
