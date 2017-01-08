#pragma once
extern string szTableA2[0x10][0x10];
extern string szTableA3[0x10][0x10];
void HexDivision(int Origin, int &HighFour, int &LowFour);
void HexDivisionS(int Origin, int &HighTwo, int &MidThree, int &LowThree);
string ByteToString(int OriginByte);

class CDasm
{
public:
	CDasm(void);
	~CDasm(void);

	bool SetStartByte(BYTE *pStartPoint);


	BYTE GetCurrentByte(); //�����õģ���ʽ�汾ɾ��
	BYTE GetStartByte();  //�����õģ���ʽ�汾ɾ��

	void TokenIteration();




private:
	string m_szASMCommand[4];
	BYTE *m_pCurrentPoint;
	BYTE *m_pStartPoint;
	int m_nOPcodeAmount;  //������¼���������ֽڣ�Ĭ����1
	int m_nHighFour;
	int m_nLowFour;
	int m_nAddressingSizeJugger; //Ĭ��32λ
	int m_nOpearantSizeJugger; //Ĭ��32λ
	//int m_nByteCounter;  //���漰һ�ζ�д��λʱ���������ƶ��Ĳ����Ľ���
	int m_nSIBSpecialSituationJugger;
	int m_nOperCodeNumberJugger;
	string m_szAddSymbol;
	string m_szRSB;  //Right Square Bracket
	string m_szLSB;  //Left Square Bracket
	string m_szColon;
	/*Ԥ��ǰ׺״̬ */

	std::vector<std::string> GiveSzValue(const std::string &s);
	BYTE *NewStart();
	void CleanSzValue();
	void OverwriteAbbreviation(int i);
	string TransModRM_RM(int Mod, int RM, int Type);
	string TransModRM_REG(int Reg, int Type);
	string TransSIB_Index(int SS, int Index);
	string TransSIB_Base(int Base);
	string TransSIB();
	string TransSIB_Base_Speical(int Mod);
	string Disp32();
	string Disp16();
	string Disp8();
	string TransGrp1(int Mid);
	string TransGrp2(int Mid);
	string TransGrp3(int Mid);
	string TransGrp4(int Mid);
	string TransGrp5(int Mid);
	string TransSw(int MidREG);
	string TransGrp1A(int Value);
	string TransCallAddr();
};

