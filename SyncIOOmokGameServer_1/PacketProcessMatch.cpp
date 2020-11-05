#include "PacketProcess.h"
#include "PacketDef.h"


namespace ChatServerLib
{
	NServerNetLib::ERROR_CODE PacketProcess::MatchUser(PacketInfo packetInfo)
	{
		NCommon::PktMatchRes resPkt;
		NCommon::PktRoomEnterRes roomResPkt;
		auto userInfo = m_pRefUserMgr->GetUser(packetInfo.SessionIndex);

		auto errorCode = userInfo.first;
		auto pUser = userInfo.second;

		if (errorCode != NServerNetLib::ERROR_CODE::NONE) 
		{
			resPkt.SetError(errorCode);
			m_pRefNetwork->SendData(packetInfo.SessionIndex, (short)NCommon::PACKET_ID::MATCH_USER_RES, sizeof(resPkt), (char*)&resPkt);
			return errorCode;
		}

		auto userIndex = pUser->GetIndex();

		auto pRoom = m_pRefRoomMgr->FindProperRoom();
		if (pRoom == nullptr) 
		{
			roomResPkt.SetError(NServerNetLib::ERROR_CODE::MATCHING_FAIL);
			m_pRefNetwork->SendData(packetInfo.SessionIndex, (short)NCommon::PACKET_ID::ROOM_ENTER_RES, sizeof(roomResPkt), (char*)&roomResPkt);
			return errorCode;
		}

		pRoom->EnterUser(pUser);
		pUser->EnterRoom(pRoom->GetIndex());
		pRoom->NotifyEnterUserInfo(userIndex, pUser->GetID().c_str());

		//TODO :  ������ ���� ����
		pRoom->m_BlackStoneUserIndex = userIndex;
		pRoom->m_TurnIndex = userIndex;
		pRoom->OmokGame->init(); 
		 
 		m_pRefNetwork->SendData(packetInfo.SessionIndex, (short)NCommon::PACKET_ID::MATCH_USER_RES, sizeof(resPkt), (char*)&resPkt);
		pRoom->SendToAllUser((short)NCommon::PACKET_ID::MATCH_USER_RES, sizeof(resPkt), (char*)&resPkt);

		return NServerNetLib::ERROR_CODE::NONE;

	}
}