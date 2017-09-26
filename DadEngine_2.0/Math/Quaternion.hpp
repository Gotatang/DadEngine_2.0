#ifndef __QUATERNION_HPP_
#define __QUATERNION_HPP_


namespace DadEngine::Math
{
	class Quaternion
	{

	public:

		Quaternion() = default;

		Quaternion(float _InW, float _InX, float _InY, float _InZ)
		{
			w = _InW;
			x = _InX;
			y = _InY;
			z = _InZ;
		}

		Quaternion(float _InAngle, Vector3f _InAxis)
		{
			float angle2 = _InAngle / 2.f;
			float sin2 = Sin(angle2);

			w = Cos(angle2);
			x = _InAxis.x * sin2;
			y = _InAxis.y * sin2;
			z = _InAxis.z * sin2;
		}

		FORCE_INLINE Quaternion Conjugate()
		{
			return Quaternion(w, -x, -y, -z);
		}

		// Binary math operators
		FORCE_INLINE Quaternion operator *(Quaternion& _InQuat)
		{
			return Quaternion(
				w * _InQuat.w - x * _InQuat.x - y * _InQuat.y - z * _InQuat.z,
				w * _InQuat.x + x * _InQuat.w + y * _InQuat.z - z * _InQuat.y,
				w * _InQuat.y - x * _InQuat.z + y * _InQuat.w + z * _InQuat.x,
				w * _InQuat.z + x * _InQuat.y - y * _InQuat.x + z * _InQuat.w);
		}

		// Binary assignement math operators
		FORCE_INLINE void operator *=(Quaternion& _InQuat)
		{
			Quaternion temp = *this;
			w = temp.w * _InQuat.w - temp.x * _InQuat.x - temp.y * _InQuat.y - temp.z * _InQuat.z;
			x = temp.w * _InQuat.x + temp.x * _InQuat.w + temp.y * _InQuat.z - temp.z * _InQuat.y;
			y = temp.w * _InQuat.y - temp.x * _InQuat.z + temp.y * _InQuat.w + temp.z * _InQuat.x;
			z = temp.w * _InQuat.z + temp.x * _InQuat.y - temp.y * _InQuat.x + temp.z * _InQuat.w;
		}

		float w = 0.f;	// Scalar part
		float x = 0.f;	// -----------
		float y = 0.f;	// Complex part
		float z = 0.f;	// -----------
	};
}

#endif //__QUATERNION_HPP_