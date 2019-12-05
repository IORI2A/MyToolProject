#include "StdAfx.h"
/*
UINT ProcessAccessConfigThread(LPVOID lParam)
{
	// 获取传递的中控设备操作控件。 CZkem1
	while(1)
	{
		// 从数据库 View_Access_DataUploadRecList 中获取配置的中控设备连接信息。
			while()  
			{
				// 逐条记录
				// （如打开密码设置宏，优先设置连接密码）先释放连接，再尝试连接。主要是检测设备是否可连接。
				// （如打开批量操作宏，断开连接）
				// 从数据库 View_Access_DataUploadRecList 中获取下发数据。
					while()  
					{
						// 逐条记录
						switch()
						{
						case 31:
							// 断开连接。
							// 设置图片 initSendPhotoFile 。
						case 1:
							// （如打开批量操作宏，断开连接）
							// 初始化设备 initAccessDeviceConfigData 。
						case 2:
						case 4:
							// （如打开批量操作宏，如打开密码设置宏，优先设置连接密码）
							// （如打开批量操作宏，断开连接，再连接）
							// 禁用设备 EnableDevice
							// 设置卡号 SetStrCardNumber
							// 设置（新增、变更）用户 SetUserInfo、SSR_SetUserInfo
							// 设置用户组 SetUserGroup
							// 设置用户组时间段 SetUserTZStr
							// 刷新数据 RefreshData
							// 启用设备 EnableDevice
							// 标识记录完成
							// （如打开批量操作宏，断开连接）
							break;
						case 3:
							// 获取存在多少指纹
							// （如打开批量操作宏，如打开密码设置宏，优先设置连接密码）
							// （如打开批量操作宏，断开连接，再连接）
							// 删除登记数据（指纹） DeleteEnrollData、SSR_GetUserTmp、SSR_DeleteEnrollData、GetUserTmpEx、SSR_DeleteEnrollDataExt
							// （如打开远程开门宏，刷新数据 RefreshData）
							// 获取指纹模板数据
							// 不同指纹算法之间的转换
							// 设置用户指纹 SetUserTmp、SetUserTmpExStr、SSR_SetUserTmp、SetUserTmpExStr
							// （如打开远程开门宏，刷新数据 RefreshData）
							// 标识记录完成
							// （如打开批量操作宏，断开连接）
						case 5:
							// （如打开批量操作宏，如打开密码设置宏，优先设置连接密码）
							// （如打开批量操作宏，断开连接，再连接）
							// 获取用户信息 GetUserInfo、SSR_GetUserInfo
							// 删除该用户及相关数据信息 DeleteEnrollData、SSR_DeleteEnrollData 。当为10是代表删除的是密码，同时会查询该用户是否有指纹数据，如没有，则删除该用户。11是代表删除该用户所有指纹数据，12代表删除该用户（包括所有指纹和卡号、密码数据）。 
							// 标识记录完成
							// （如打开批量操作宏，断开连接）
						case 6:
							// （如打开批量操作宏，如打开密码设置宏，优先设置连接密码）
							// 设置用户组 SetUserGroup
							// 设置用户组时间段 SetUserTZStr
							// 刷新数据 RefreshData
							// 标识记录完成
							// （如打开批量操作宏，断开连接）
						case 8:
							// 提取用记本地照片文件数据。
							// 设置用户照片 SendFile
							// 标识记录完成
						case 11:
							// 从数据库 Access_GroupAndTZ
							// （如打开批量操作宏，如打开密码设置宏，优先设置连接密码）
							// 设置组时间段 SetGroupTZStr、SSR_SetGroupTZ
							// 标识记录完成
							// （如打开批量操作宏，断开连接）
						case 12:
							// （如打开批量操作宏，如打开密码设置宏，优先设置连接密码）
							// 删除组时间段 SetGroupTZStr、SSR_SetGroupTZ
							// 标识记录完成
							// （如打开批量操作宏，断开连接）
						case 13:
							// 下发默认语音 EnableCustomizeVoice、SetCustomizeVoice
							// 标识记录完成
						default:			
						}
					}//end of while data
				// （如打开批量操作宏，断开连接）
			}//end of while device
		// （如果打开人脸模板宏 收集人脸模板 CollectFaceTemplate ）
	}// end of while(1)
}


BOOL initAccessDeviceConfigData(ZKDeviceType zkDevType,int deviceID,CString deviceIPAddr, int haveFingerSenseOrNot,int havePhoto,CZkem1 * pm_ZkemConfig,CZKFPEngX * pm_Zkfp,int AcceptNoUserCard,int AcceptVisitCard, int HaveFaceVerify)
{
	// （如打开密码设置宏，设置连接密码）
	// 先释放连接，再尝试连接。
	// 禁用设备 EnableDevice
	// 清空数据 ClearKeeperData
	// （隐藏设置不自动关机、不自动休眠 SetDeviceInfo ）
	// 从数据库 View_AccessDevice_GroupAndTZ 获取组及时间段
	// 设置时间段 SetTZInfo
	// 设置组时间段 SetGroupTZStr、SSR_SetGroupTZ
	// 设置开锁组合 SetUnlockGroups、SSR_SetUnLockGroup （清空）
	// 从数据库 Access_UnLockGroups 中获取开锁组合配置
	// 设置开锁组合 SetUnlockGroups、SSR_SetUnLockGroup （设置）
	// 如果使用默认, 设置开锁组合 SetUnlockGroups、SSR_SetUnLockGroup （默认）
		// 从数据库 View_AccessDevice_UserList、Base_CardInformation、Base_VisitorCardInformation、Base_SuperCardInformation、Base_VacationCardInformation 获取用户数据
			// （如打开批量操作宏，启用批处理 BeginBatchUpdate ）
			while()  
			{
				// 逐条记录
				// 设置卡 SetStrCardNumber
				// 设置用户 SetUserInfo、SSR_SetUserInfo
				// 设置用户组 SetUserGroup
				// 设置用户时间段 SetUserTZStr
				// 不同算法的指纹模板转换
				// 设置用户指纹模板 SetUserTmpExStr、SetUserTmp、SSR_SetUserTmp
			}
			// （如打开批量操作宏，进行批处理 BatchUpdate ）
			
			// 回到记录集头
			while()  
			{
				// 逐条记录
				// （如打开批量操作宏，设置用户组 SetUserGroup ，设置用户时间段 SetUserTZStr）
				// 获取照片
				// 下发人脸模板，先删除 DelUserFace ，再设置人脸模板 SetUserFaceStr
				// 照片下传 SendFile
			}
	// 刷新数据 RefreshData
	// 启用设备 EnableDevice
	// 断开设备连接 Disconnect
}
*/