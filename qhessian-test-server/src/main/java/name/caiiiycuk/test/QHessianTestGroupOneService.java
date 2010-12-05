package name.caiiiycuk.test;

import java.util.Date;

/**
 * Interface for Group 1 tests <br/>
 * http://code.google.com/p/qhessian/wiki/QHessian_QA
 * @author caiiiycuk
 */
public interface QHessianTestGroupOneService {
	
	//
	// read/write raw data
	//
	byte[] 	readRaw();
	
	void  	writeRaw(byte[] data);
	
	//
	//	read/write boolean
	//
	void 	readBooleanTrue();

	void	writeBooleanTrue(boolean bool);
	
	void 	readBooleanFalse();

	void	writeBooleanFalse(boolean bool);
	
	//
	//	read/write 64-bit millisecond date
	//
	
	Date	readDate();
	
	void	writeDate(Date date);

	//
	//	read/write 64-bit double
	//
	
	double 	readDouble();
	
	Double 	readDoubleObject();
	
	Double 	readDoubleObjectNull();
	
	void   	writeDouble(double d);
	
	void   	writeDoubleObject(Double d);
	
	void 	writeDoubleNull(Double d);
	
	//
	//	read/write 32-bit int
	//
	
	int 	readInteger();
	
	Integer readIntegerObject();
	
	Integer readIntegerObjectNull();
	
	void   	writeInteger(int d);
	
	void   	writeIntegerObject(Integer i);
	
	void 	writeIntegerNull(Integer i);
	
	//
	//	read/write 64-bit long
	//
	
	long 	readLong();
	
	Long 	readLongObject();
	
	Long 	readLongObjectNull();
	
	void   	writeLong(long l);
	
	void   	writeLongObject(Long l);
	
	void 	writeLongNull(Long l);
	
	//
	// read/write null
	//
	
	Object  readNull();
	
	void    writeNull();
	
	//
	//	read/write UTF8-encoded string
	//
	
	String 	readString();
	
	String	readStringNull();
	
	void	writeString(String aString);

	void 	writeStringNull(String aNullString);
}
