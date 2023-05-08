//******************************************************************
// 
//  Generated by RoboCompDSL
//  
//  File name: CameraRGBDSimpleMulti.ice
//  Source: CameraRGBDSimpleMulti.idsl
//
//******************************************************************
#ifndef ROBOCOMPCAMERARGBDSIMPLEMULTI_ICE
#define ROBOCOMPCAMERARGBDSIMPLEMULTI_ICE
module RoboCompCameraRGBDSimpleMulti
{
	exception HardwareFailedException{ string what; };
	sequence <byte> ImgType;
	sequence <byte> DepthType;
	struct TImage
	{
		bool compressed;
		int cameraID;
		int width;
		int height;
		int depth;
		int focalx;
		int focaly;
		long alivetime;
		float period;
		ImgType image;
	};
	struct TDepth
	{
		bool compressed;
		int cameraID;
		int width;
		int height;
		int focalx;
		int focaly;
		long alivetime;
		float period;
		float depthFactor;
		DepthType depth;
	};
	struct TRGBD
	{
		TImage image;
		TDepth depth;
	};
	interface CameraRGBDSimpleMulti
	{
		TRGBD getAll (int robotid, string camera) throws HardwareFailedException;
		TDepth getDepth (int robotid, string camera) throws HardwareFailedException;
		TImage getImage (int robotid, string camera) throws HardwareFailedException;
	};
};

#endif
