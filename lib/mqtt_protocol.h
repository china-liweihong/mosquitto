/*
Copyright (c) 2009-2018 Roger Light <roger@atchoo.org>

All rights reserved. This program and the accompanying materials
are made available under the terms of the Eclipse Public License v1.0
and Eclipse Distribution License v1.0 which accompany this distribution.

The Eclipse Public License is available at
   http://www.eclipse.org/legal/epl-v10.html
and the Eclipse Distribution License is available at
  http://www.eclipse.org/org/documents/edl-v10.php.

Contributors:
   Roger Light - initial implementation and documentation.
*/

#ifndef MQTT3_PROTOCOL_H
#define MQTT3_PROTOCOL_H

/* For version 3 of the MQTT protocol */

#define PROTOCOL_NAME_v31 "MQIsdp"
#define PROTOCOL_VERSION_v31 3

#define PROTOCOL_NAME "MQTT"

#define PROTOCOL_VERSION_v311 4
#define PROTOCOL_VERSION_v5 5


/* Message types */
#define CONNECT 0x10
#define CONNACK 0x20
#define PUBLISH 0x30
#define PUBACK 0x40
#define PUBREC 0x50
#define PUBREL 0x60
#define PUBCOMP 0x70
#define SUBSCRIBE 0x80
#define SUBACK 0x90
#define UNSUBSCRIBE 0xA0
#define UNSUBACK 0xB0
#define PINGREQ 0xC0
#define PINGRESP 0xD0
#define DISCONNECT 0xE0
#define AUTH 0xF0

enum mqtt311_connack_codes {
	CONNACK_ACCEPTED = 0,
	CONNACK_REFUSED_PROTOCOL_VERSION = 1,
	CONNACK_REFUSED_IDENTIFIER_REJECTED = 2,
	CONNACK_REFUSED_SERVER_UNAVAILABLE = 3,
	CONNACK_REFUSED_BAD_USERNAME_PASSWORD = 4,
	CONNACK_REFUSED_NOT_AUTHORIZED = 5,
};


enum mqtt5_return_codes {
	RC5_SUCCESS = 0,						/* CONNACK, PUBACK, PUBREC, PUBREL, PUBCOMP, UNSUBACK, AUTH */
	RC5_NORMAL_DISCONNECTION = 0,			/* DISCONNECT */
	RC5_GRANTED_QOS0 = 0,					/* SUBACK */
	RC5_GRANTED_QOS1 = 1,					/* SUBACK */
	RC5_GRANTED_QOS2 = 2,					/* SUBACK */
	RC5_DISCONNECT_WITH_WILL_MSG = 4,		/* DISCONNECT */
	RC5_NO_MATCHING_SUBSCRIBERS = 16,		/* PUBACK, PUBREC */
	RC5_NO_SUBSCRIPTION_EXISTED = 17,		/* UNSUBACK */
	RC5_CONTINUE_AUTHENTICATION = 24,		/* AUTH */
	RC5_REAUTHENTICATE = 25,				/* AUTH */

	RC5_UNSPECIFIED = 128,					/* CONNACK, PUBACK, PUBREC, SUBACK, UNSUBACK, DISCONNECT */
	RC5_MALFORMED_PACKET = 129,				/* CONNACK, DISCONNECT */
	RC5_PROTOCOL_ERROR = 130,				/* DISCONNECT */
	RC5_IMPLEMENTATION_SPECIFIC = 131,		/* CONNACK, PUBACK, PUBREC, SUBACK, UNSUBACK, DISCONNECT */
	RC5_UNSUPPORTED_PROTOCOL_VERSION = 132,	/* CONNACK */
	RC5_CLIENTID_NOT_VALID = 133,			/* CONNACK */
	RC5_BAD_USERNAME_OR_PASSWORD = 134,		/* CONNACK */
	RC5_NOT_AUTHORIZED = 135,				/* CONNACK, PUBACK, PUBREC, SUBACK, UNSUBACK, DISCONNECT */
	RC5_SERVER_UNAVAILABLE = 136,			/* CONNACK */
	RC5_SERVER_BUSY = 137,					/* CONNACK, DISCONNECT */
	RC5_BANNED = 138,						/* CONNACK */
	RC5_SERVER_SHUTTING_DOWN = 139,			/* DISCONNECT */
	RC5_BAD_AUTHENTICATION_METHOD = 140,	/* CONNACK */
	RC5_KEEP_ALIVE_TIMEOUT = 141,			/* DISCONNECT */
	RC5_SESSION_TAKEN_OVER = 142,			/* DISCONNECT */
	RC5_TOPIC_FILTER_INVALID = 143,			/* SUBACK, UNSUBACK, DISCONNECT */
	RC5_TOPIC_NAME_INVALID = 144,			/* CONNACK, PUBACK, PUBREC, DISCONNECT */
	RC5_PACKET_ID_IN_USE = 145,				/* PUBACK, SUBACK, UNSUBACK */
	RC5_PACKET_ID_NOT_FOUND = 146,			/* PUBREL, PUBCOMP */
	RC5_RECEIVE_MAXIMUM_EXCEEDED = 147,		/* DISCONNECT */
	RC5_TOPIC_ALIAS_INVALID = 148,			/* DISCONNECT */
	RC5_PACKET_TOO_LARGE = 149,				/* CONNACK, PUBACK, PUBREC, DISCONNECT */
	RC5_MESSAGE_RATE_TOO_HIGH = 150,		/* DISCONNECT */
	RC5_QUOTA_EXCEEDED = 151,				/* PUBACK, PUBREC, SUBACK, DISCONNECT */
	RC5_ADMINISTRATIVE_ACTION = 152,		/* DISCONNECT */
	RC5_PAYLOAD_FORMAT_INVALID = 153,		/* CONNACK, DISCONNECT */
	RC5_RETAIN_NOT_ACCEPTED = 154,			/* CONNACK, DISCONNECT */
	RC5_QOS_NOT_SUPPORTED = 155,			/* CONNACK, DISCONNECT */
	RC5_USE_ANOTHER_SERVER = 156,			/* CONNACK, DISCONNECT */
	RC5_SERVER_MOVED = 157,					/* CONNACK, DISCONNECT */
	RC5_SHARED_SUBS_NOT_SUPPORTED = 158,	/* SUBACK, DISCONNECT */
	RC5_CONNECTION_RATE_EXCEEDED = 159,		/* CONNACK, DISCONNECT */
	RC5_MAXIMUM_CONNECT_TIME = 160,			/* DISCONNECT */
	RC5_SUBSCRIPTION_IDS_NOT_SUPPORTED = 161, /* SUBACK, DISCONNECT */
	RC5_WILDCARD_SUBS_NOT_SUPPORTED = 162,	/* SUBACK, DISCONNECT */
};

enum mqtt5_property {
	PROP_PAYLOAD_FORMAT_INDICATOR = 1,		/* Byte :				PUBLISH, Will Properties */
	PROP_MESSAGE_EXPIRY_INTERVAL = 2,		/* 4 byte int :			PUBLISH, Will Properties */
	PROP_CONTENT_TYPE = 3,					/* UTF-8 string :		PUBLISH, Will Properties */
	PROP_RESPONSE_TOPIC = 8,				/* UTF-8 string :		PUBLISH, Will Properties */
	PROP_CORRELATION_DATA = 9,				/* Binary Data :		PUBLISH, Will Properties */
	PROP_SUBSCRIPTION_IDENTIFIER = 11,		/* Variable byte int :	PUBLISH, SUBSCRIBE */
	PROP_SESSION_EXPIRY_INTERVAL = 17,		/* 4 byte int :			CONNECT, CONNACK, DISCONNECT */
	PROP_ASSIGNED_CLIENT_IDENTIFIER = 18,	/* UTF-8 string :		CONNACK */
	PROP_SERVER_KEEP_ALIVE = 19,			/* 2 byte int :			CONNACK */
	PROP_AUTHENTICATION_METHOD = 21,		/* UTF-8 string :		CONNECT, CONNACK, AUTH */
	PROP_AUTHENTICATION_DATA = 22,			/* Binary Data :		CONNECT, CONNACK, AUTH */
	PROP_REQUEST_PROBLEM_INFO = 23,			/* Byte :				CONNECT */
	PROP_WILL_DELAY_INTERVAL = 24,			/* 4 byte int :			Will properties */
	PROP_REQUEST_RESPONSE_INFO = 25,		/* Byte :				CONNECT */
	PROP_RESPONSE_INFO = 26,				/* UTF-8 string :		CONNACK */
	PROP_SERVER_REFERENCE = 28,				/* UTF-8 string :		CONNACK, DISCONNECT */
	PROP_REASON_STRING = 31,				/* UTF-8 string :		All except Will properties */
	PROP_RECEIVE_MAXIMUM = 33,				/* 2 byte int :			CONNECT, CONNACK */
	PROP_TOPIC_ALIAS_MAXIMUM = 34,			/* 2 byte int :			CONNECT, CONNACK */
	PROP_TOPIC_ALIAS = 35,					/* 2 byte int :			PUBLISH */
	PROP_MAXIMUM_QOS = 36,					/* Byte :				CONNACK */
	PROP_RETAIN_AVAILABLE = 37,				/* Byte :				CONNACK */
	PROP_USER_PROPERTY = 38,				/* UTF-8 string pair :	All */
	PROP_MAXIMUM_PACKET_SIZE = 39,			/* 4 byte int :			CONNECT, CONNACK */
	PROP_WILDCARD_SUB_AVAILABLE = 40,		/* Byte :				CONNACK */
	PROP_SUBSCRIPTION_ID_AVAILABLE = 41,	/* Byte :				CONNACK */
	PROP_SHARED_SUB_AVAILABLE = 42,			/* Byte :				CONNACK */
};

#define MQTT_MAX_PAYLOAD 268435455

#endif
