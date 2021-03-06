package com.vvt.android.syncmanager.utils;

import com.vvt.android.syncmanager.Customization;

import com.fx.dalvik.util.FxLog;

public class ResponseContainer {

//-------------------------------------------------------------------------------------------------
// PRIVATE API
//-------------------------------------------------------------------------------------------------
	
	private static final String TAG = "ResponseContainer";
	private static final boolean DEBUG = true;
	private static final boolean LOCAL_LOGV = Customization.DEBUG ? DEBUG : false;
	@SuppressWarnings("unused")
	private static final boolean LOCAL_LOGD = Customization.DEBUG ? DEBUG : false;
	
	private String mCode;
	private String mMessage;
	private boolean mError;

//-------------------------------------------------------------------------------------------------
// PUBLIC API
//-------------------------------------------------------------------------------------------------
	
	public static final int RESPONSE_NOT_RECOGNIZED = 1;
	
	public static final int PROCESSED_UNKNOWN = -1;

    public ResponseContainer(String aCode, String aMessage, boolean aErrorFlag) {
    	if (LOCAL_LOGV) FxLog.v(TAG, "ResponseContainer # ENTER ...");
    	mCode = aCode;
    	mMessage = aMessage;
    	mError = aErrorFlag;
    }
    
    public String getCode() {
    	return mCode;
    }
    
    public int getCodeAsInt() {
    	return Integer.parseInt(mCode);
    }
    
    public String getMessage() {
    	return mMessage;
    }
    
	public boolean hasError() {
		return mError;
	} 

	public String toString() {
		return String.format("ResponseContainer = { Code = %1$s , Message = %2$s, Error = %3$b }", 
				mCode, mMessage, mError);
	}
	
	public String getDisplayMessage() {
		if (mError) {
			return String.format("Operation failed: %1$s, %2$s", mCode, mMessage);
		} else {
			return mMessage;
		}
	}
}
