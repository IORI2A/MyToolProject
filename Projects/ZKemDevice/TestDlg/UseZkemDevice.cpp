#include "StdAfx.h"
/*
UINT ProcessAccessConfigThread(LPVOID lParam)
{
	// ��ȡ���ݵ��п��豸�����ؼ��� CZkem1
	while(1)
	{
		// �����ݿ� View_Access_DataUploadRecList �л�ȡ���õ��п��豸������Ϣ��
			while()  
			{
				// ������¼
				// ������������ú꣬���������������룩���ͷ����ӣ��ٳ������ӡ���Ҫ�Ǽ���豸�Ƿ�����ӡ�
				// ��������������꣬�Ͽ����ӣ�
				// �����ݿ� View_Access_DataUploadRecList �л�ȡ�·����ݡ�
					while()  
					{
						// ������¼
						switch()
						{
						case 31:
							// �Ͽ����ӡ�
							// ����ͼƬ initSendPhotoFile ��
						case 1:
							// ��������������꣬�Ͽ����ӣ�
							// ��ʼ���豸 initAccessDeviceConfigData ��
						case 2:
						case 4:
							// ��������������꣬����������ú꣬���������������룩
							// ��������������꣬�Ͽ����ӣ������ӣ�
							// �����豸 EnableDevice
							// ���ÿ��� SetStrCardNumber
							// ���ã�������������û� SetUserInfo��SSR_SetUserInfo
							// �����û��� SetUserGroup
							// �����û���ʱ��� SetUserTZStr
							// ˢ������ RefreshData
							// �����豸 EnableDevice
							// ��ʶ��¼���
							// ��������������꣬�Ͽ����ӣ�
							break;
						case 3:
							// ��ȡ���ڶ���ָ��
							// ��������������꣬����������ú꣬���������������룩
							// ��������������꣬�Ͽ����ӣ������ӣ�
							// ɾ���Ǽ����ݣ�ָ�ƣ� DeleteEnrollData��SSR_GetUserTmp��SSR_DeleteEnrollData��GetUserTmpEx��SSR_DeleteEnrollDataExt
							// �����Զ�̿��ź꣬ˢ������ RefreshData��
							// ��ȡָ��ģ������
							// ��ָͬ���㷨֮���ת��
							// �����û�ָ�� SetUserTmp��SetUserTmpExStr��SSR_SetUserTmp��SetUserTmpExStr
							// �����Զ�̿��ź꣬ˢ������ RefreshData��
							// ��ʶ��¼���
							// ��������������꣬�Ͽ����ӣ�
						case 5:
							// ��������������꣬����������ú꣬���������������룩
							// ��������������꣬�Ͽ����ӣ������ӣ�
							// ��ȡ�û���Ϣ GetUserInfo��SSR_GetUserInfo
							// ɾ�����û������������Ϣ DeleteEnrollData��SSR_DeleteEnrollData ����Ϊ10�Ǵ���ɾ���������룬ͬʱ���ѯ���û��Ƿ���ָ�����ݣ���û�У���ɾ�����û���11�Ǵ���ɾ�����û�����ָ�����ݣ�12����ɾ�����û�����������ָ�ƺͿ��š��������ݣ��� 
							// ��ʶ��¼���
							// ��������������꣬�Ͽ����ӣ�
						case 6:
							// ��������������꣬����������ú꣬���������������룩
							// �����û��� SetUserGroup
							// �����û���ʱ��� SetUserTZStr
							// ˢ������ RefreshData
							// ��ʶ��¼���
							// ��������������꣬�Ͽ����ӣ�
						case 8:
							// ��ȡ�üǱ�����Ƭ�ļ����ݡ�
							// �����û���Ƭ SendFile
							// ��ʶ��¼���
						case 11:
							// �����ݿ� Access_GroupAndTZ
							// ��������������꣬����������ú꣬���������������룩
							// ������ʱ��� SetGroupTZStr��SSR_SetGroupTZ
							// ��ʶ��¼���
							// ��������������꣬�Ͽ����ӣ�
						case 12:
							// ��������������꣬����������ú꣬���������������룩
							// ɾ����ʱ��� SetGroupTZStr��SSR_SetGroupTZ
							// ��ʶ��¼���
							// ��������������꣬�Ͽ����ӣ�
						case 13:
							// �·�Ĭ������ EnableCustomizeVoice��SetCustomizeVoice
							// ��ʶ��¼���
						default:			
						}
					}//end of while data
				// ��������������꣬�Ͽ����ӣ�
			}//end of while device
		// �����������ģ��� �ռ�����ģ�� CollectFaceTemplate ��
	}// end of while(1)
}


BOOL initAccessDeviceConfigData(ZKDeviceType zkDevType,int deviceID,CString deviceIPAddr, int haveFingerSenseOrNot,int havePhoto,CZkem1 * pm_ZkemConfig,CZKFPEngX * pm_Zkfp,int AcceptNoUserCard,int AcceptVisitCard, int HaveFaceVerify)
{
	// ������������ú꣬�����������룩
	// ���ͷ����ӣ��ٳ������ӡ�
	// �����豸 EnableDevice
	// ������� ClearKeeperData
	// ���������ò��Զ��ػ������Զ����� SetDeviceInfo ��
	// �����ݿ� View_AccessDevice_GroupAndTZ ��ȡ�鼰ʱ���
	// ����ʱ��� SetTZInfo
	// ������ʱ��� SetGroupTZStr��SSR_SetGroupTZ
	// ���ÿ������ SetUnlockGroups��SSR_SetUnLockGroup ����գ�
	// �����ݿ� Access_UnLockGroups �л�ȡ�����������
	// ���ÿ������ SetUnlockGroups��SSR_SetUnLockGroup �����ã�
	// ���ʹ��Ĭ��, ���ÿ������ SetUnlockGroups��SSR_SetUnLockGroup ��Ĭ�ϣ�
		// �����ݿ� View_AccessDevice_UserList��Base_CardInformation��Base_VisitorCardInformation��Base_SuperCardInformation��Base_VacationCardInformation ��ȡ�û�����
			// ��������������꣬���������� BeginBatchUpdate ��
			while()  
			{
				// ������¼
				// ���ÿ� SetStrCardNumber
				// �����û� SetUserInfo��SSR_SetUserInfo
				// �����û��� SetUserGroup
				// �����û�ʱ��� SetUserTZStr
				// ��ͬ�㷨��ָ��ģ��ת��
				// �����û�ָ��ģ�� SetUserTmpExStr��SetUserTmp��SSR_SetUserTmp
			}
			// ��������������꣬���������� BatchUpdate ��
			
			// �ص���¼��ͷ
			while()  
			{
				// ������¼
				// ��������������꣬�����û��� SetUserGroup �������û�ʱ��� SetUserTZStr��
				// ��ȡ��Ƭ
				// �·�����ģ�壬��ɾ�� DelUserFace ������������ģ�� SetUserFaceStr
				// ��Ƭ�´� SendFile
			}
	// ˢ������ RefreshData
	// �����豸 EnableDevice
	// �Ͽ��豸���� Disconnect
}
*/