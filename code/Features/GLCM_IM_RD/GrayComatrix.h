//////////////////////////////////////////////////////////////////////
// GrayShow.h: interface for the CGrayComatrix class.
// ����������Ҷȹ��־����㷨ʵ��
// 
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAYMATRIX_H_INCLUDED_)
#define AFX_GRAYMATRIX_H_INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define FEATURE_NUM 12

//#include "Dib.h"

class CGrayComatrix  
{
public:
	//����
	double FeatureLocalCalmRD;	//�ֲ�ƽ���ԣ�45�ȷ���
	double FeatureLocalCalmLD;	//�ֲ�ƽ���ԣ�135�ȷ���
	double FeatureLocalCalmV;	//�ֲ�ƽ���ԣ�90�ȷ���ȷ���
	double FeatureLocalCalmH;	//�ֲ�ƽ���ԣ�0�ȷ���
	double FeatureCorrelationRD;	//����ԣ�45�ȷ���
	double FeatureCorrelationLD;	//����ԣ�135�ȷ���
	double FeatureCorrelationV;		//����ԣ�90�ȷ���
	double FeatureCorrelationH;		//����ԣ�0�ȷ���
	double FeatureInertiaQuadratureRD;	//���Ծأ�45�ȷ���
	double FeatureInertiaQuadratureLD;	//���Ծأ�135�ȷ���
	double FeatureInertiaQuadratureV;	//���Ծأ�90�ȷ���
	double FeatureInertiaQuadratureH;	//���Ծأ�0�ȷ���
	double FeatureEntropyRD;	//�أ�45�ȷ���
	double FeatureEntropyLD;	//�أ�135�ȷ���
	double FeatureEntropyV;		//�أ�90�ȷ���
	double FeatureEntropyH;		//�أ�0�ȷ���
	double FeatureEnergyRD;		//������45�ȷ���
	double FeatureEnergyLD;		//������135�ȷ���
	double FeatureEnergyV;		//������90�ȷ���
	double FeatureEnergyH;		//������0�ȷ���
	int FilterWindowWidth;	//���������Ĵ�С��ͨ����ͼ�񻮷ֳ����ɸ���������
	long ImageHeight;	//ԭͼ��ĸ߶�
	long ImageWidth;		//ԭͼ��Ŀ��
	int distance;	//���룬���ݲ�ͬ��Ӧ��ѡȡ	
	int GrayLayerNum;	//�Ҷȷּ�
	int** PMatrixRD;	//45�ȷ����ϵĻҶȹ��־���
	int** PMatrixLD;	//135�ȷ����ϵĻҶȹ��־���
	int** PMatrixV;		//90�ȷ����ϵĻҶȹ��־���
	int** PMatrixH;		//0�ȷ����ϵĻҶȹ��־���
	BYTE** ImageArray;	//ԭʼ��ͼ���������飭�Ҷ�
	
		//����ֵ��0��1��2��3�ֱ�ָ0�㡢90�㡢45�㡢135��
	/*��������ָ��
			1. ����(�Ƕ��׾�)(E)
			2. ��(H)		
			3. �����
			4. ���أ�ͬ�ʶ�HOM��(L)
			5. ���ԣ��Աȶȣ������Ծأ�(CON)(I)
			6. �Ҷ���(Hf)
			7. �ݶ���(hg)
			8. �ݶȷֲ���������(Ug)
			9. С�ݶ�����Tmin��
			10. ���ݶ�����Tmax��
			11. ����
			12. ��ֵ��
	*/
	int		m_iFeatureNum;
	double	m_dFeatures[16][4];
	double	m_duFeatures[16];
	double	m_dsFeatures[16];
	RGBQUAD** m_tOriPixelArray;//ԭʼλͼ����
	RGBQUAD** m_tResPixelArray;//�ο�λͼ����
	
//	CDib *m_dib;
	
	//����
	void LoadImage(CString &FilePathName);
	void ComputeMatrix(BYTE** LocalImage, int LocalImageWidth, int LocalImageHeight);
	void ComputeFeature(int nFeature, int** pMatrix, int iDir, int iDim);
	void OnComputeFeature(int nFeature, double *duFeatures, double *dsFeatures);

	CGrayComatrix();
	virtual ~CGrayComatrix();
	
};

#define PIC_NUM 2000

#endif // !defined(AFX_GRAYMATRIX_H_INCLUDED_)
