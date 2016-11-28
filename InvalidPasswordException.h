#ifndef __INVALIDPASSWORDEXCEPTION_H__
#define __INVALIDPASSWORDEXCEPTION_H__


class InvalidPasswordException
{
	protected:
		char *msg;
		int code;
		
		
	public:
		static int BAD_LENGTH_ERROR, MISSING_ALPHA_ERROR, MISSING_DIGIT_ERROR;
		//init
		InvalidPasswordException()
		{msg = NULL;};
		
		InvalidPasswordException(int x)
		{msg = NULL;setCode(x);};
		
		InvalidPasswordException(int x, const char *tmp)
		{msg = NULL;setCode(x);setMsg(tmp);};
		
		InvalidPasswordException(const InvalidPasswordException &tmp);
		~InvalidPasswordException();
		
		//getteur setteur
		int setMsg(const char *tmp);
		char *getMsg() const {return msg;};
		int setCode(int x){code = x;return 1;};
		int getCode()const {return code;};
		
		//autre
		void perror(const char *tmp);
		
		
};


#endif
