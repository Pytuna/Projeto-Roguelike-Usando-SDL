#include "Vector2D.hpp"

Vector2D &Vector2D::Add(const Vector2D &vec)
{
    this->x += vec.x;
    this->y += vec.y;

    return *this;
}

Vector2D &Vector2D::Sub(const Vector2D &vec)
{
    this->x -= vec.x;
    this->y -= vec.y;

    return *this;
}

Vector2D &Vector2D::Mul(const Vector2D &vec)
{
    this->x *= vec.x;
    this->y *= vec.y;

    return *this;
}

Vector2D &Vector2D::Div(const Vector2D &vec)
{
    this->x /= vec.x;
    this->y /= vec.y;

    return *this;
}

Vector2D &operator+(Vector2D &v1, const Vector2D &v2)
{
    return v1.Add(v2);
}

Vector2D &operator-(Vector2D &v1, const Vector2D &v2)
{
    return v1.Sub(v2);
}

Vector2D &operator*(Vector2D &v1, const Vector2D &v2)
{
    return v1.Mul(v2);
}

Vector2D &operator/(Vector2D &v1, const Vector2D &v2)
{
    return v1.Div(v2);
}
Vector2D &Vector2D::operator+=(const Vector2D &vec)
{
    return this->Add(vec);
}

Vector2D &Vector2D::operator-=(const Vector2D &vec)
{
    return this->Sub(vec);
}

Vector2D &Vector2D::operator*=(const Vector2D &vec)
{
    return this->Mul(vec);
}

Vector2D &Vector2D::operator/=(const Vector2D &vec)
{
    return this->Div(vec);
}
std::ostream &operator<<(std::ostream &stream, const Vector2D &vec)
{
    stream << "(" << vec.x << ", " << vec.y << ")";
    return stream;
}