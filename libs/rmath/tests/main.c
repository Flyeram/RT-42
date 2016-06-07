#include <rmath.h>
#include <stdio.h>

/*
**	DEFINES
*/

int main(void)
{
	printf("DEFINES/MACROS TEST\n\n");
	printf("PI : %f\n", PI);
	t_vector2f vector2;

	printf("\n%s", "Vector2\n");
	vector2 = V2F_INIT(99.42, 12.12);
	printf("%-15s : %15f : %15f\n", "Custom", vector2.x, vector2.y);
	vector2 = V2F_ZERO;
	printf("%-15s : %15f : %15f\n", "Zero", vector2.x, vector2.y);
	vector2 = V2F_ONE;
	printf("%-15s : %15f : %15f\n", "One", vector2.x, vector2.y);
	vector2 = V2F_UP;
	printf("%-15s : %15f : %15f\n", "Up", vector2.x, vector2.y);
	vector2 = V2F_DOWN;
	printf("%-15s : %15f : %15f\n", "Down", vector2.x, vector2.y);
	vector2 = V2F_RIGHT;
	printf("%-15s : %15f : %15f\n", "Right", vector2.x, vector2.y);
	vector2 = V2F_LEFT;
	printf("%-15s : %15f : %15f\n", "Left", vector2.x, vector2.y);

	t_vector3f vector3;

	printf("\n%s", "Vector3\n");
	vector3 = V3F_INIT(99.42, 12.12, 43.12);
	printf("%-15s : %15f : %15f : %15f\n", "Custom", vector3.x, vector3.y, vector3.z);
	vector3 = V3F_ZERO;
	printf("%-15s : %15f : %15f : %15f\n", "Zero", vector3.x, vector3.y, vector3.z);
	vector3 = V3F_ONE;
	printf("%-15s : %15f : %15f : %15f\n", "One", vector3.x, vector3.y, vector3.z);
	vector3 = V3F_FORWARD;
	printf("%-15s : %15f : %15f : %15f\n", "Forward", vector3.x, vector3.y, vector3.z);
	vector3 = V3F_BACK;
	printf("%-15s : %15f : %15f : %15f\n", "Back", vector3.x, vector3.y, vector3.z);
	vector3 = V3F_UP;
	printf("%-15s : %15f : %15f : %15f\n", "Up", vector3.x, vector3.y, vector3.z);
	vector3 = V3F_DOWN;
	printf("%-15s : %15f : %15f : %15f\n", "Down", vector3.x, vector3.y, vector3.z);
	vector3 = V3F_RIGHT;
	printf("%-15s : %15f : %15f : %15f\n", "Right", vector3.x, vector3.y, vector3.z);
	vector3 = V3F_LEFT;
	printf("%-15s : %15f : %15f : %15f\n", "Left", vector3.x, vector3.y, vector3.z);

	t_vector4f vector4;

	printf("\n%s", "Vector4\n");
	vector4 = V4F_INIT(99.42, 12.12, 43.12, 42.42);
	printf("%-15s : %15f : %15f : %15f : %15f\n", "Custom", vector4.x, vector4.y, vector4.z, vector4.w);
	vector4 = V4F_ZERO;
	printf("%-15s : %15f : %15f : %15f : %15f\n", "Zero", vector4.x, vector4.y, vector4.z, vector4.w);
	vector4 = V4F_ONE;
	printf("%-15s : %15f : %15f : %15f : %15f\n", "One", vector4.x, vector4.y, vector4.z, vector4.w);
	vector4 = V4F_FORWARD;
	printf("%-15s : %15f : %15f : %15f : %15f\n", "Forward", vector4.x, vector4.y, vector4.z, vector4.w);
	vector4 = V4F_BACK;
	printf("%-15s : %15f : %15f : %15f : %15f\n", "Back", vector4.x, vector4.y, vector4.z, vector4.w);
	vector4 = V4F_UP;
	printf("%-15s : %15f : %15f : %15f : %15f\n", "Up", vector4.x, vector4.y, vector4.z, vector4.w);
	vector4 = V4F_DOWN;
	printf("%-15s : %15f : %15f : %15f : %15f\n", "Down", vector4.x, vector4.y, vector4.z, vector4.w);
	vector4 = V4F_RIGHT;
	printf("%-15s : %15f : %15f : %15f : %15f\n", "Right", vector4.x, vector4.y, vector4.z, vector4.w);
	vector4 = V4F_LEFT;
	printf("%-15s : %15f : %15f : %15f : %15f\n", "Left", vector4.x, vector4.y, vector4.z, vector4.w);

	return (0);
}
