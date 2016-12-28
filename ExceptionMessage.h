#ifndef __EXCEPTIONMESSAGE_H__
#define __EXCEPTIONMESSAGE_H__


class ExceptionMessage
{
	protected:
		char *msg;
		int nbrErr;
		int setMsg(const char *tmp);
		int setNbrErr(int n)
		{nbrErr = n; return 1;};
		
	public:
		//init
		ExceptionMessage()
		{msg = NULL; nbrErr=0;};
		ExceptionMessage(const char *tmp)
		{msg = NULL; nbrErr=0; setMsg(tmp);};
		
		ExceptionMessage(const char *tmp, int n)
		{msg = NULL; nbrErr=0; setMsg(tmp); setNbrErr(n);};
		
		ExceptionMessage(const ExceptionMessage &tmp);
		~ExceptionMessage();
		
		char *getMsg() const {return msg;};
		int getNbrErr() const {return nbrErr;};
};


#endif
