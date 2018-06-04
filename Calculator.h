#pragma once

#define FPS 80.0f

#define SECONDE_TO_FRAME(s) s * FPS
#define MINUTE_TO_FRAME(m)  m * FPS * FPS
#define HOUR_TO_FRAME(h)    h * FPS * FPS * FPS

#define FRAME_TO_SECOND(f) f * (1 / FPS)
#define FRAME_TO_MINUTE(f) f * (1 / FPS / FPS)
#define FRAME_TO_HOUR(f)   f * (1 / FPS / FPS / FPS)

//-------------------------------------
// ���ش����� m�� ���ϰ�
// 1m = 1 pixel �� ���
//-------------------------------------
#define MM_TO_PIXEL(mm) 0.001  * mm
#define CM_TO_PIXEL(cm) 0.01 * cm
#define M_TO_PIXEL(m)   1 * m
#define KM_TO_PIXEL(km) 1000 * km

#define PIXEL_TO_MM(pixel) pixel * 1000
#define PIXEL_TO_CM(pixel) pixel * 100
#define PIXEL_TO_M(pixel)  pixel
#define PIXEL_TO_KM(pixel) pixel * 0.001

class CSpeed
{
private:
	// ���� �Ұ�
	CSpeed() {}

public:
	static double PixelPerSecond(double second, double pixel) { return pixel / SECONDE_TO_FRAME(second); }
	static double PixelPerMinute(double minute, double pixel)  { return pixel / MINUTE_TO_FRAME(minute); }

 	static double MillimeterPerSecond(double second, double mm) { return MM_TO_PIXEL(mm) / SECONDE_TO_FRAME(second); }
	static double CentimeterPerSecond(double second, double cm) { return CM_TO_PIXEL(cm) / SECONDE_TO_FRAME(second); }
	static double MeterPerSecond(double second, double m)       { return m / SECONDE_TO_FRAME(second); }
	static double KilometerPerSecond(double second, double km)  { return KM_TO_PIXEL(km) / SECONDE_TO_FRAME(second); }

	static double MillimeterPerMinute(double minute, double mm) { return MM_TO_PIXEL(mm) / MINUTE_TO_FRAME(minute); }
	static double CentimeterPerMinute(double minute, double cm) { return CM_TO_PIXEL(cm) / MINUTE_TO_FRAME(minute); }
	static double MeterPerMinute(double minute, double m)       { return m / MINUTE_TO_FRAME(minute); }
	static double KilometerPerMinute(double minute, double km)  { return KM_TO_PIXEL(km) / MINUTE_TO_FRAME(minute); }

	static double MillimeterPerFrame(double frame, double mm)   { return MM_TO_PIXEL(mm) / frame; }
	static double CentimeterPerFrame(double frame, double cm)   { return CM_TO_PIXEL(cm) / frame; }
	static double MeterPerFrame(double frame, double m)         { return m / frame; }
	static double KilometerPerFrame(double frame, double km)    { return KM_TO_PIXEL(km) / frame; }
};