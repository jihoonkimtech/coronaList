#ifndef __STRINGLIB_H
#define __STRINGLIB_H

//�Լ� ���� 
void ct_strcpy (char* dest, char* src);

//�Լ� �ۼ� 
void ct_strcpy (char* dest, char* src) {
	while (*src) {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

#endif

