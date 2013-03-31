// InvariantMoment.h: interface for the CInvariantMoment class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INVARIANTMOMENT_H__41E859A2_FD08_41F5_80B3_117253940769__INCLUDED_)
#define AFX_INVARIANTMOMENT_H__41E859A2_FD08_41F5_80B3_117253940769__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CInvariantMoment : public CObject  
{
//Atrributes:
public:
	double Fi1;         //7�������
	double Fi2;
	double Fi3;
	double Fi4;
	double Fi5;
	double Fi6;
	double Fi7;

	double	m_dIM[7];
	double	m_dIM_Norm[7];
	double	m_dExIM[10];

	double yita20;      //7����������õ���yitaֵ
	double yita02;
	double yita11;
	double yita30;
	double yita03;
	double yita12;
	double yita21;

	LONG	m_lMui00;

	int		m_iImgWidth;        //ͼ����
	int		m_iImgHeight;       //ͼ��߶�
	BYTE	**m_pImageData;		//ͼ��������ָ��
	BYTE	*m_pImageEdge;		//ͼ��߽�����
	int		m_mx;				//ͼ������x����
	int		m_my;				//ͼ������y����
	LONG  LineBytes;			//ͼ�����ֽ���
//Functions
public:
	CInvariantMoment();
	CInvariantMoment(LPSTR lpBits,LONG Width,LONG Height);
	virtual ~CInvariantMoment();
	double ComputeM(int p,int q);     //�������ĺ���
	double Miu(int p,int q);          //����Miu����
	double YT(int p,int q);           //����Fi����
	void ComputeFi(double dIM[], double dExIM[]);      //����7�������
	void SetImgData(BYTE ** pImage, BYTE *pEdge, int w, int h);
	void OnCanny();
};

#endif // !defined(AFX_INVARIANTMOMENT_H__41E859A2_FD08_41F5_80B3_117253940769__INCLUDED_)
