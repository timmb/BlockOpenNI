#pragma once

#include <string>
#include <vector>
#include <boost/cstdint.hpp>
#include "VOpenNICommon.h"
#include "VOpenNIBone.h"



namespace V
{
	// Forward declaration
	class OpenNIDevice;


	enum UserState
	{
		USER_NONE,
		USER_TRACKING,
		USER_LOOKING_FOR_POSE,
		USER_CALIBRATING
	};


	typedef std::vector<Bone*> UserBoneList;
	class OpenNIUser
	{
		friend class OpenNIDeviceManager;

	public:
		OpenNIUser( boost::int32_t id, OpenNIDevice* device );
		~OpenNIUser();
		void OpenNIUser::update();
		void OpenNIUser::updatePixels();
		void OpenNIUser::updateBody();
		void OpenNIUser::renderJoints( float pointSize );


		UserBoneList	getBoneList();
		Bone*			getBone( int id );

		void			setText( const std::string& info )	{ _debugInfo = info; }
		const std::string& getText()		{ return _debugInfo; }

		bool			hasPixels()			{ return (_userPixels)?true:false;}
		boost::uint8_t*	getPixels()			{ return _userPixels; }
		uint32_t		getId()				{ return mId; }
		float*			getCenterOfMass()	{ return mCenter; }

	protected:
		OpenNIDevice*	_device;
		std::string		_debugInfo;
		uint8_t*		_userPixels;

		uint32_t		mId;
		float			mCenter[3];	// Center point

		float			mColor[3];

		int				mBoneIndexArray[BONE_COUNT];
		UserBoneList	mBoneList;
	};


	//
	// Manager
	//
	/***class OpenNIPlayerManager
	{
	public:
		OpenNIPlayerManager( OpenNI* openni );
		~OpenNIPlayerManager();
		boost::int32_t OpenNIPlayerManager::registerPlayer( uint32_t id, void* newUserFunc, void* lostUserFunc );


	protected:
		OpenNI*		_openni;

		std::shared_ptr<std::vector<OpenNIPlayer*>> mPlayerList;
	};***/
}