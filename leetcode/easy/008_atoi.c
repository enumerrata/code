int myAtoi(char* str) {
	long long v=0;
	char *p = str;
	int sign = 1;
	int i=1;

	while (*p == ' ')
		p++;
	
	if (!*p)
		return 0;
   
   	if (*p == '+' || *p == '-') {
		if (*p == '-')
			sign = -1;
		p++; 
	}

	if (*p<'0' || *p>'9')
		return 0;

	while (*p>='0' && *p<='9') {
		v = v*10 + (*p - '0');
		p++;
		if (i++ > 11)
			break;
	}

	if (v > 2147483647 && sign > 0) 
		return INT_MAX; 

	if (v > 2147483648 && sign < 0)
		return INT_MIN;

	return sign * v;
}

int main(int argc, char *argv[])
{
	printf("%d\n", myAtoi("+-2"));
	return 0;
}


