
#ifndef MATH_MAT4_H
#define MATH_MAT4_H

#include "GeoMath/math/Vec3.h"
#include "GeoMath/math/Vec4.h"
#include "Geomath/math/Quaternion.h"
class  Quaternion;
class Mat4
{
public:
   
    float m[16];

    Mat4();

    Mat4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24,
           float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44);

    Mat4(const float* mat);

    Mat4(const Mat4& copy);

    ~Mat4();

    static void createLookAt(const Vec3& eyePosition, const Vec3& targetPosition, const Vec3& up, Mat4* dst);

    static void createLookAt(float eyePositionX, float eyePositionY, float eyePositionZ,
                             float targetCenterX, float targetCenterY, float targetCenterZ,
                             float upX, float upY, float upZ, Mat4* dst);

    static void createPerspective(float fieldOfView, float aspectRatio, float zNearPlane, float zFarPlane, Mat4* dst);

    static void createOrthographic(float width, float height, float zNearPlane, float zFarPlane, Mat4* dst);

    static void createOrthographicOffCenter(float left, float right, float bottom, float top,
                                            float zNearPlane, float zFarPlane, Mat4* dst);

    static void createBillboard(const Vec3& objectPosition, const Vec3& cameraPosition,
                                const Vec3& cameraUpVector, Mat4* dst);


    static void createBillboard(const Vec3& objectPosition, const Vec3& cameraPosition,
                                const Vec3& cameraUpVector, const Vec3& cameraForwardVector,
                                Mat4* dst);

    static void createScale(const Vec3& scale, Mat4* dst);

    static void createScale(float xScale, float yScale, float zScale, Mat4* dst);

    static void createRotation(const Quaternion& quat, Mat4* dst);

    static void createRotation(const Vec3& axis, float angle, Mat4* dst);

    static void createRotationX(float angle, Mat4* dst);

    static void createRotationY(float angle, Mat4* dst);

    static void createRotationZ(float angle, Mat4* dst);

    static void createTranslation(const Vec3& translation, Mat4* dst);

    static void createTranslation(float xTranslation, float yTranslation, float zTranslation, Mat4* dst);

    void add(float scalar);

    void add(float scalar, Mat4* dst);

    void add(const Mat4& mat);

    static void add(const Mat4& m1, const Mat4& m2, Mat4* dst);

    bool decompose(Vec3* scale, Quaternion* rotation, Vec3* translation) const;

    float determinant() const;

    void getScale(Vec3* scale) const;

    bool getRotation(Quaternion* rotation) const;

    void getTranslation(Vec3* translation) const;

    void getUpVector(Vec3* dst) const;

    void getDownVector(Vec3* dst) const;

    void getLeftVector(Vec3* dst) const;

    void getRightVector(Vec3* dst) const;

    void getForwardVector(Vec3* dst) const;

    void getBackVector(Vec3* dst) const;

    bool inverse();

    Mat4 getInversed() const;

    bool isIdentity() const;

    void multiply(float scalar);

    void multiply(float scalar, Mat4* dst) const;

    static void multiply(const Mat4& mat, float scalar, Mat4* dst);

    void multiply(const Mat4& mat);

    static void multiply(const Mat4& m1, const Mat4& m2, Mat4* dst);

    void negate();

    Mat4 getNegated() const;

    void rotate(const Quaternion& q);

    void rotate(const Quaternion& q, Mat4* dst) const;

    void rotate(const Vec3& axis, float angle);

    void rotate(const Vec3& axis, float angle, Mat4* dst) const;

    void rotateX(float angle);

    void rotateX(float angle, Mat4* dst) const;

    void rotateY(float angle);

    void rotateY(float angle, Mat4* dst) const;

    void rotateZ(float angle);

    void rotateZ(float angle, Mat4* dst) const;

    void scale(float value);

    void scale(float value, Mat4* dst) const;

    void scale(float xScale, float yScale, float zScale);

    void scale(float xScale, float yScale, float zScale, Mat4* dst) const;

    void scale(const Vec3& s);

    void scale(const Vec3& s, Mat4* dst) const;

    void set(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24,
             float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44);

    void set(const float* mat);

    void set(const Mat4& mat);

    void setIdentity();

    void setZero();

    void subtract(const Mat4& mat);

    static void subtract(const Mat4& m1, const Mat4& m2, Mat4* dst);

    inline void transformPoint(Vec3* point) const { transformVector(point->x, point->y, point->z, 1.0f, point); }

    inline void transformPoint(const Vec3& point, Vec3* dst) const { transformVector(point.x, point.y, point.z, 1.0f, dst); }

    void transformVector(Vec3* vector) const;

    void transformVector(const Vec3& vector, Vec3* dst) const;

    void transformVector(float x, float y, float z, float w, Vec3* dst) const;

    void transformVector(Vec4* vector) const;

    void transformVector(const Vec4& vector, Vec4* dst) const;

    void translate(float x, float y, float z);

    void translate(float x, float y, float z, Mat4* dst) const;

    void translate(const Vec3& t);

    void translate(const Vec3& t, Mat4* dst) const;

    void transpose();

    Mat4 getTransposed() const;

    inline Mat4 operator+(const Mat4& mat) const;
    
    inline Mat4& operator+=(const Mat4& mat);

    inline Mat4 operator-(const Mat4& mat) const;

    inline Mat4& operator-=(const Mat4& mat);

    inline Mat4 operator-() const;

    inline Mat4 operator*(const Mat4& mat) const;

    inline Mat4& operator*=(const Mat4& mat);

    static const Mat4 ZERO;
    static const Mat4 IDENTITY;

private:

    static void createBillboardHelper(const Vec3& objectPosition, const Vec3& cameraPosition,
                                      const Vec3& cameraUpVector, const Vec3* cameraForwardVector,
                                      Mat4* dst);
};

inline Vec3& operator*=(Vec3& v, const Mat4& m);

inline Vec3 operator*(const Mat4& m, const Vec3& v);

inline Vec4& operator*=(Vec4& v, const Mat4& m);

inline Vec4 operator*(const Mat4& m, const Vec4& v);

#include "GeoMath/math/Mat4.inl"

#endif // MATH_MAT4_H