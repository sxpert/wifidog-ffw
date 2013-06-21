/********************************************************************\
 * This program is free software; you can redistribute it and/or    *
 * modify it under the terms of the GNU General Public License as   *
 * published by the Free Software Foundation; either version 2 of   *
 * the License, or (at your option) any later version.              *
 *                                                                  *
 * This program is distributed in the hope that it will be useful,  *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of   *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    *
 * GNU General Public License for more details.                     *
 *                                                                  *
 * You should have received a copy of the GNU General Public License*
 * along with this program; if not, contact:                        *
 *                                                                  *
 * Free Software Foundation           Voice:  +1-617-542-5942       *
 * 59 Temple Place - Suite 330        Fax:    +1-617-542-2652       *
 * Boston, MA  02111-1307,  USA       gnu@gnu.org                   *
 *                                                                  *
\********************************************************************/

/* $Id: fw_iptables.h 901 2006-01-17 18:58:13Z mina $ */
/** @file fw_iptables.h
    @brief Firewall iptables functions
    @author Copyright (C) 2004 Philippe April <papril777@yahoo.com>
*/

#ifndef _FW_IPTABLES_H_
#define _FW_IPTABLES_H_

#include "firewall.h"

/*@{*/ 
/**Iptable table names used by WifiDog */
#define TABLE_WIFIDOG_OUTGOING  "WiFiDog_Outgoing"
#define TABLE_WIFIDOG_WIFI_TO_INTERNET "WiFiDog_WIFI2Internet"
#define TABLE_WIFIDOG_WIFI_TO_ROUTER "WiFiDog_WIFI2Router"
#define TABLE_WIFIDOG_INCOMING  "WiFiDog_Incoming"
#define TABLE_WIFIDOG_AUTHSERVERS "WiFiDog_AuthServers"
#define TABLE_WIFIDOG_GLOBAL  "WiFiDog_Global"
#define TABLE_WIFIDOG_VALIDATE  "WiFiDog_Validate"
#define TABLE_WIFIDOG_KNOWN     "WiFiDog_Known"
#define TABLE_WIFIDOG_MEMBERS     "WiFiDog_Members"
#define TABLE_WIFIDOG_UNKNOWN   "WiFiDog_Unknown"
#define TABLE_WIFIDOG_LOCKED    "WiFiDog_Locked"
#define TABLE_WIFIDOG_TRUSTED    "WiFiDog_Trusted"
/*@}*/ 

/** Used by iptables_fw_access to select if the client should be granted of denied access */
typedef enum fw_access_t_ {
    FW_ACCESS_ALLOW,
    FW_ACCESS_DENY
} fw_access_t;

/** @brief Initialize the firewall */
int iptables_fw_init(void);

/** @brief Initializes the authservers table */
void iptables_fw_set_authservers(void);

/** @brief Clears the authservers table */
void iptables_fw_clear_authservers(void);

/** @brief Destroy the firewall */
int iptables_fw_destroy(void);

/** @brief Helper function for iptables_fw_destroy */
int iptables_fw_destroy_mention( char * table, char * chain, char * mention);

/** @brief Define the access of a specific client */
int iptables_fw_access(fw_access_t type, char *ip, char *mac, int tag);

/** @brief All counters in the client list */
int iptables_fw_counters_update(void);

#endif /* _IPTABLES_H_ */