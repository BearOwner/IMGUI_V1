

#include <string>
#include <utility>

namespace
{
    constexpr int const_atoi(char c)
    {
        return c - '0';
    }
}

#ifdef _MSC_VER
#define ALWAYS_INLINE __forceinline
#else
#define ALWAYS_INLINE __attribute__((always_inline))
#endif

template<typename _string_type, size_t _length>
class _Basic_XorStr
{
    using value_type = typename _string_type::value_type;
    static constexpr auto _length_minus_one = _length - 1;

public:
    constexpr ALWAYS_INLINE _Basic_XorStr(value_type const (&str)[_length])
        : _Basic_XorStr(str, std::make_index_sequence<_length_minus_one>())
    {

    }

    inline auto c_str() const
    {
        decrypt();

        return data;
    }
   

    inline auto str() const
    {
        decrypt();

        return _string_type(data, data + _length_minus_one);
    }

    inline operator _string_type() const
    {
        return str();
    }

private:
    template<size_t... indices>
    constexpr ALWAYS_INLINE _Basic_XorStr(value_type const (&str)[_length], std::index_sequence<indices...>)
        : data{ crypt(str[indices], indices)..., '\0' },
        encrypted(true)
    {

    }

    static constexpr auto XOR_KEY = static_cast<value_type>(
        const_atoi(__TIME__[7]) +
        const_atoi(__TIME__[6]) * 10 +
        const_atoi(__TIME__[4]) * 60 +
        const_atoi(__TIME__[3]) * 600 +
        const_atoi(__TIME__[1]) * 3600 +
        const_atoi(__TIME__[0]) * 36000
        );
        

    static ALWAYS_INLINE constexpr auto crypt(value_type c, size_t i)
    {
        return static_cast<value_type>(c ^ (XOR_KEY + i));
    }

    inline void decrypt() const
    {
        if (encrypted)
        {
            for (size_t t = 0; t < _length_minus_one; t++)
            {
                data[t] = crypt(data[t], t);
            }
            encrypted = false;
        }
    }

    
    mutable value_type data[_length];
    mutable bool encrypted;
};
//---------------------------------------------------------------------------
template<size_t _length>
using XorStrA = _Basic_XorStr<std::string, _length>;
template<size_t _length>
using XorStrW = _Basic_XorStr<std::wstring, _length>;
template<size_t _length>
using XorStrU16 = _Basic_XorStr<std::u16string, _length>;
template<size_t _length>
using XorStrU32 = _Basic_XorStr<std::u32string, _length>;
//---------------------------------------------------------------------------
template<typename _string_type, size_t _length, size_t _length2>
inline auto operator==(const _Basic_XorStr<_string_type, _length> &lhs, const _Basic_XorStr<_string_type, _length2> &rhs)
{
    static_assert(_length == _length2, "XorStr== different length");

    return _length == _length2 && lhs.str() == rhs.str();
}
//---------------------------------------------------------------------------
template<typename _string_type, size_t _length>
inline auto operator==(const _string_type &lhs, const _Basic_XorStr<_string_type, _length> &rhs)
{
    return lhs.size() == _length && lhs == rhs.str();
}
//---------------------------------------------------------------------------
template<typename _stream_type, typename _string_type, size_t _length>
inline auto& operator<<(_stream_type &lhs, const _Basic_XorStr<_string_type, _length> &rhs)
{
    lhs << rhs.c_str();

    return lhs;
}
//---------------------------------------------------------------------------
template<typename _string_type, size_t _length, size_t _length2>
inline auto operator+(const _Basic_XorStr<_string_type, _length> &lhs, const _Basic_XorStr<_string_type, _length2> &rhs)
{
    return lhs.str() + rhs.str();
}
//---------------------------------------------------------------------------
template<typename _string_type, size_t _length>
inline auto operator+(const _string_type &lhs, const _Basic_XorStr<_string_type, _length> &rhs)
{
    return lhs + rhs.str();
}
//---------------------------------------------------------------------------
template<size_t _length>
constexpr ALWAYS_INLINE auto _xor_(char const (&str)[_length])
{
    return XorStrA<_length>(str);
}
//---------------------------------------------------------------------------
template<size_t _length>
constexpr ALWAYS_INLINE auto _xor_(wchar_t const (&str)[_length])
{
    return XorStrW<_length>(str);
}
//---------------------------------------------------------------------------
template<size_t _length>
constexpr ALWAYS_INLINE auto _xor_(char16_t const (&str)[_length])
{
    return XorStrU16<_length>(str);
}
//---------------------------------------------------------------------------
template<size_t _length>
constexpr ALWAYS_INLINE auto _xor_(char32_t const (&str)[_length])
{
    return XorStrU32<_length>(str);
}






FMatrix RotatorToMatrix(FRotator rotation) {
    float radPitch = rotation.Pitch * ((float) PI / 180.f);
    float radYaw = rotation.Yaw * ((float) PI / 180.f);
    float radRoll = rotation.Roll * ((float) PI / 180.f);

    float SP = sinf(radPitch);
    float CP = cosf(radPitch);
    float SY = sinf(radYaw);
    float CY = cosf(radYaw);
    float SR = sinf(radRoll);
    float CR = cosf(radRoll);

    FMatrix matrix;

    matrix.M[0][0] = (CP * CY);
    matrix.M[0][1] = (CP * SY);
    matrix.M[0][2] = (SP);
    matrix.M[0][3] = 0;

    matrix.M[1][0] = (SR * SP * CY - CR * SY);
    matrix.M[1][1] = (SR * SP * SY + CR * CY);
    matrix.M[1][2] = (-SR * CP);
    matrix.M[1][3] = 0;

    matrix.M[2][0] = (-(CR * SP * CY + SR * SY));
    matrix.M[2][1] = (CY * SR - CR * SP * SY);
    matrix.M[2][2] = (CR * CP);
    matrix.M[2][3] = 0;

    matrix.M[3][0] = 0;
    matrix.M[3][1] = 0;
    matrix.M[3][2] = 0;
    matrix.M[3][3] = 1;

    return matrix;
}




FVector2D WorldToScreen(FVector worldLocation, FMinimalViewInfo camViewInfo, int width, int height) {
    FMatrix tempMatrix = RotatorToMatrix(camViewInfo.Rotation);
    
    
FVector vAxisX(tempMatrix.M[0][0], tempMatrix.M[0][1], tempMatrix.M[0][2]);
    FVector vAxisY(tempMatrix.M[1][0], tempMatrix.M[1][1], tempMatrix.M[1][2]);
    FVector vAxisZ(tempMatrix.M[2][0], tempMatrix.M[2][1], tempMatrix.M[2][2]);

    FVector vDelta = worldLocation - camViewInfo.Location;
    
    FVector vTransformed(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

    if (vTransformed.Z < 1.0f) {
        vTransformed.Z = 1.0f;
    }
    
    float fov = camViewInfo.FOV;
    float screenCenterX = (width / 2.0f);
    float screenCenterY = (height / 2.0f);
    
    return FVector2D(
                     (screenCenterX + vTransformed.X * (screenCenterX / tanf(fov * ((float) M_PI / 360.0f))) / vTransformed.Z),
                     (screenCenterY - vTransformed.Y * (screenCenterX / tanf(fov * ((float) M_PI / 360.0f))) / vTransformed.Z)
                     );
    
    
}
