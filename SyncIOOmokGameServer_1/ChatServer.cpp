﻿#include <thread>
#include <chrono>

#include "ErrorCode.h"
#include "Define.h"
#include "ChatServer.h"

#include <iostream>
#include "RoomManager.h"
namespace ChatServerLib
{
	ChatServer::ChatServer()
	{

	}

	ChatServer::~ChatServer()
	{
		if (m_pNetwork) 
		{
			m_pNetwork->Stop();
		}
	}

	NServerNetLib::ERROR_CODE ChatServer::Init(const NServerNetLib::ServerConfig pConfig)
	{

		m_pNetwork = std::make_unique<NServerNetLib::TcpNetwork>();
		auto result = m_pNetwork->Init(pConfig);

		if (result != NServerNetLib::NET_ERROR_CODE::NONE)
		{
			return NServerNetLib::ERROR_CODE::MAIN_INIT_NETWORK_INIT_FAIL;
		}

		m_pUserMgr = std::make_unique<UserManager>();
		m_pUserMgr->Init(pConfig.MaxClientCount);

		m_pRoomMgr = std::make_unique<RoomManager>();
		m_pRoomMgr->Init(pConfig.MaxRoomCountByLobby, m_pNetwork.get());

		m_pPacketProc = std::make_unique<PacketProcess>();
		m_pPacketProc->Init(m_pNetwork.get(), m_pUserMgr.get(),m_pRoomMgr.get(), pConfig);

		m_IsRun = true;

		return NServerNetLib::ERROR_CODE::NONE;
	}
	
	void ChatServer::Stop()
	{
		m_IsRun = false;
	}

	void ChatServer::Run()
	{
		while (m_IsRun)
		{
			m_pNetwork->Run();

			while (true) 
			{
				auto packetInfo = m_pNetwork->GetReceivePacket();
				
				if (packetInfo.PacketId == 0) 
				{
					break;
				}
				else 
				{
					m_pPacketProc->Process(packetInfo);
				}
			}
		}
	}
}