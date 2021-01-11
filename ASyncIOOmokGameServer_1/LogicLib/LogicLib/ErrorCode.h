
namespace OmokServerLib
{

	enum class ERROR_CODE : short
	{
		NONE = 0,

		UNASSIGNED_ERROR = 201,

		MAIN_INIT_NETWORK_INIT_FAIL = 206,

		USER_MGR_ID_DUPLICATION = 211,
		USER_MGR_MAX_USER_COUNT = 212,
		USER_MGR_INVALID_SESSION_INDEX = 213,
		USER_MGR_NOT_CONFIRM_USER = 214,
		USER_MGR_REMOVE_INVALID_SESSION = 221,

		USER_ROOM_FIND_ERROR = 270,
		ROOM_ENTER_INVALID_DOMAIN = 271,
		ROOM_ENTER_INVALID_LOBBY_INDEX = 272,
		ROOM_ENTER_INVALID_ROOM_INDEX = 273,
		ROOM_ENTER_CREATE_FAIL = 274,
		ROOM_ENTER_NOT_CREATED = 275,
		ROOM_ENTER_MEMBER_FULL = 276,
		ROOM_ENTER_EMPTY_ROOM = 277,

		MATCHING_FAIL = 278,

		USER_STATE_NOT_ROOM = 285,
		ROOM_LEAVE_INVALID_DOMAIN = 286,
		ROOM_LEAVE_INVALID_LOBBY_INDEX = 287,
		ROOM_LEAVE_INVALID_ROOM_INDEX = 288,
		ROOM_LEAVE_NOT_CREATED = 289,
		ROOM_LEAVE_NOT_MEMBER = 290,

		ROOM_CHAT_INVALID_DOMAIN = 296,
		ROOM_CHAT_INVALID_LOBBY_INDEX = 297,
		ROOM_CHAT_INVALID_ROOM_INDEX = 298,

		GAME_NOT_YOUR_TURN = 300,
		GAME_PUT_ALREADY_EXIST = 301,
		GAME_PUT_SAM_SAM = 302,
		GAME_PUT_POS_ERROR = 303,

		GAME_RESULT_BLACK_WIN = 304,
		GAME_RESULT_WHITE_WIN = 305,

		NOT_READY_EXIST = 306,
		NOT_YOUR_TURN = 307,

		ALREADY_GAME_STATE = 308,
		ALREADY_READY_STATE = 309,

		USER_STATE_NOT_GAME = 310,

		REDIS_ALREADY_CONNECT_STATE = 320,
		REDIS_CONNECT_FAIL = 321,
		REDIS_COMMAND_FAIL = 322,
		REDIS_GET_FAIL = 323,
		REDIS_RECEIVE_TIME_OUT=324,

		REDIS_LOGIN_PW_INCORRECT=325,
		ALREADY_LOGIN_STATE = 326


	};
}
#pragma once
