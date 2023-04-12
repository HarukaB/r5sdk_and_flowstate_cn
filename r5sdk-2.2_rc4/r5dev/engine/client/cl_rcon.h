#pragma once
#include "tier1/NetAdr.h"
#include "tier2/socketcreator.h"
#include "protoc/sv_rcon.pb.h"
#include "protoc/cl_rcon.pb.h"

class CRConClient
{
public:
	CRConClient(void);
	~CRConClient(void);

	void Init(void);
	void Shutdown(void);

	void RunFrame(void);

	bool Connect(void);
	bool Connect(const char* szInAdr);
	void Disconnect(void);

	void Send(const string& svMessage) const;
	void Recv(void);

	void ProcessBuffer(const char* pRecvBuf, int nRecvLen, CConnectedNetConsoleData* pData);
	void ProcessMessage(const sv_rcon::response& sv_response) const;

	string Serialize(const string& svReqBuf, const string& svReqVal, const cl_rcon::request_t request_t) const;
	sv_rcon::response Deserialize(const string& svBuf) const;

	bool IsInitialized(void) const;
	bool IsConnected(void) const;

private:
	bool m_bInitialized = false;
	bool m_bConnEstablished = false;

	netadr_t m_Address;
	CSocketCreator m_Socket;
};

CRConClient* RCONClient();