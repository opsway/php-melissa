/************************************************/
/* Melissa Data									*/
/* Thinh Truong									*/
/* Date: 04/03/2006								*/
/* PHP Wrapper for Address Object (mdAddr.dll)	*/
/************************************************/

#include "php.h"
#include <stdlib.h>
#include <stdio.h>
#include "mdAddrPHP.h"

zend_function_entry mdaddrphp_functions[] =
{
/* declaration of functions to be exported */
    ZEND_FE(mdaddrcreate, NULL)
    ZEND_FE(mdaddrdestroy, NULL)
   
     /*setupmethods*/
    ZEND_FE(mdaddrinitialize, NULL)
    ZEND_FE(mdaddrgetinitializeerrorstring, NULL)
    ZEND_FE(mdaddrsetlicensestring, NULL)
    ZEND_FE(mdaddrgetbuildnumber, NULL)
    ZEND_FE(mdaddrgetdatabasedate, NULL)
    ZEND_FE(mdaddrgetexpirationdate, NULL)
    ZEND_FE(mdaddrsetpathtousfiles, NULL)
    ZEND_FE(mdaddrsetpathtodpvdatafiles, NULL)
	ZEND_FE(mdaddrsetpathtolacslinkdatafiles, NULL)
	ZEND_FE(mdaddrsetpathtorbdifiles, NULL)
	ZEND_FE(mdaddrsetpathtocanadafiles, NULL)
    ZEND_FE(mdaddrclearproperties, NULL)
    ZEND_FE(mdaddrinitializedatafiles, NULL)
    ZEND_FE(mdaddrgetrbdidatabasedate, NULL)
    
    /*errorsandstatus*/
    ZEND_FE(mdaddrgetstatuscode, NULL)
    ZEND_FE(mdaddrgeterrorcode, NULL)
    ZEND_FE(mdaddrgeterrorstring, NULL)
    
    /*cassform3553methods*/
    ZEND_FE(mdaddrsetps3553_b1_processorname, NULL)
    ZEND_FE(mdaddrsetps3553_b4_listname, NULL)
    ZEND_FE(mdaddrsetps3553_d3_name, NULL)
    ZEND_FE(mdaddrsetps3553_d3_company, NULL)
    ZEND_FE(mdaddrsetps3553_d3_address, NULL)
    ZEND_FE(mdaddrsetps3553_d3_city, NULL)
    ZEND_FE(mdaddrsetps3553_d3_state, NULL)
    ZEND_FE(mdaddrsetps3553_d3_zip, NULL)
    ZEND_FE(mdaddrgetformps3553, NULL)
    ZEND_FE(mdaddrsaveformps3553, NULL)
    ZEND_FE(mdaddrresetformps3553, NULL)
	ZEND_FE(mdaddrresetdpv, NULL)

	/* Form PS3553 fields */
	ZEND_FE(mdaddrgetps3553_b6_totalrecords, NULL)
	ZEND_FE(mdaddrgetps3553_c1a_zip4coded, NULL)
	ZEND_FE(mdaddrgetps3553_c1c_dpbcassigned, NULL)
	ZEND_FE(mdaddrgetps3553_c1d_fivedigitcoded, NULL)
	ZEND_FE(mdaddrgetps3553_c1e_crrtcoded, NULL)
	ZEND_FE(mdaddrgetps3553_c1f_elotassigned, NULL)
	ZEND_FE(mdaddrgetps3553_e_highrisedefault, NULL)
	ZEND_FE(mdaddrgetps3553_e_highriseexact, NULL)
	ZEND_FE(mdaddrgetps3553_e_ruralroutedefault, NULL)
	ZEND_FE(mdaddrgetps3553_e_ruralrouteexact, NULL)
	ZEND_FE(mdaddrgetps3553_e_lacscount, NULL)
	ZEND_FE(mdaddrgetps3553_e_ewscount, NULL)
	ZEND_FE(mdaddrgetps3553_e_dpvcount, NULL)
	
    /*requiredinput*/
    ZEND_FE(mdaddrsetcompany, NULL)
    ZEND_FE(mdaddrsetaddress, NULL)
    ZEND_FE(mdaddrsetaddress2, NULL)
    ZEND_FE(mdaddrsetlastline, NULL)
    ZEND_FE(mdaddrsetsuite, NULL)
    ZEND_FE(mdaddrsetcity, NULL)
    ZEND_FE(mdaddrsetstate, NULL)
    ZEND_FE(mdaddrsetzip, NULL)
    ZEND_FE(mdaddrsetplus4, NULL)
    ZEND_FE(mdaddrseturbanization, NULL)
    
     /*Optionalinput*/
    ZEND_FE(mdaddrsetparsedaddressrange, NULL)
    ZEND_FE(mdaddrsetparsedpredirection, NULL)
    ZEND_FE(mdaddrsetparsedstreetname, NULL)
    ZEND_FE(mdaddrsetparsedsuffix, NULL)
    ZEND_FE(mdaddrsetparsedpostdirection, NULL)
    ZEND_FE(mdaddrsetparsedsuitename, NULL)
    ZEND_FE(mdaddrsetparsedsuiterange, NULL)
    ZEND_FE(mdaddrsetcountrycode, NULL)
    
    /*processingmethod*/
    ZEND_FE(mdaddrverifyaddress, NULL)

    /*Outputdata*/
    ZEND_FE(mdaddrgetcompany, NULL)
    ZEND_FE(mdaddrgetaddress, NULL)
    ZEND_FE(mdaddrgetaddress2, NULL)
	ZEND_FE(mdaddrgetsuite, NULL)
    ZEND_FE(mdaddrgetcity, NULL)
    ZEND_FE(mdaddrgetcityabbreviation, NULL)
    ZEND_FE(mdaddrgetstate, NULL)
    ZEND_FE(mdaddrgetzip, NULL)
    ZEND_FE(mdaddrgetplus4, NULL)
    ZEND_FE(mdaddrgetcarrierroute, NULL)

    ZEND_FE(mdaddrgetdeliverypointcode, NULL)
    ZEND_FE(mdaddrgetdeliverypointcheckdigit, NULL)  
    ZEND_FE(mdaddrgetcountyfips, NULL) 
	ZEND_FE(mdaddrgetcountyname, NULL) 
    ZEND_FE(mdaddrgetaddresstypecode, NULL) 
    ZEND_FE(mdaddrgetaddresstypestring, NULL)
    ZEND_FE(mdaddrgeturbanization, NULL)
    ZEND_FE(mdaddrgetcongressionaldistrict, NULL)
    ZEND_FE(mdaddrgetlacs, NULL)
	ZEND_FE(mdaddrgetlacslinkindicator, NULL)

	ZEND_FE(mdaddrgetprivatemailbox, NULL)
	ZEND_FE(mdaddrgettimezonecode, NULL)
	ZEND_FE(mdaddrgettimezone, NULL)
	ZEND_FE(mdaddrgetmsa, NULL)
	ZEND_FE(mdaddrgetpmsa, NULL)
	ZEND_FE(mdaddrgetdefaultflagindicator, NULL)
	ZEND_FE(mdaddrgetsuitestatus, NULL)
	ZEND_FE(mdaddrgetewsflag, NULL)
	ZEND_FE(mdaddrgetcmra, NULL)
	ZEND_FE(mdaddrgetcountrycode, NULL)
	ZEND_FE(mdaddrgetziptype, NULL)
	ZEND_FE(mdaddrgetfalsetable, NULL)
	ZEND_FE(mdaddrgetdpvfootnotes, NULL)
	ZEND_FE(mdaddrgetlacslinkreturncode, NULL)
	ZEND_FE(mdaddrgetrbdi, NULL)
    
    /*parsedinputdata*/
    ZEND_FE(mdaddrgetparsedaddressrange, NULL)
    ZEND_FE(mdaddrgetparsedpredirection, NULL)
    ZEND_FE(mdaddrgetparsedstreetname, NULL)
    ZEND_FE(mdaddrgetparsedsuffix, NULL)
    ZEND_FE(mdaddrgetparsedpostdirection, NULL)
    ZEND_FE(mdaddrgetparsedsuitename, NULL)
    ZEND_FE(mdaddrgetparsedsuiterange, NULL)
    ZEND_FE(mdaddrgetparsedprivatemailboxname, NULL)
    ZEND_FE(mdaddrgetparsedprivatemailboxnumber, NULL)
    ZEND_FE(mdaddrgetparsedgarbage, NULL)


    /*********************************/
    /*    Parse Interface				     */
    /*********************************/
    ZEND_FE(mdparsecreate, NULL)
    ZEND_FE(mdparsedestroy, NULL)
    
    /* Setup methods */
    ZEND_FE(mdparseinitialize, NULL)
    ZEND_FE(mdparsegetbuildnumber, NULL)
    
    /* Processing method */
    ZEND_FE(mdparseparse, NULL)
    ZEND_FE(mdparseparsenext, NULL)
    ZEND_FE(mdparselastlineparse, NULL)
    
    /* Output data */
    ZEND_FE(mdparsegetzip, NULL)
    ZEND_FE(mdparsegetplus4, NULL)
    ZEND_FE(mdparsegetcity, NULL)
    ZEND_FE(mdparsegetstate, NULL)
    ZEND_FE(mdparsegetstreetname, NULL)
    ZEND_FE(mdparsegetrange, NULL)
    ZEND_FE(mdparsegetpredirection, NULL)
    ZEND_FE(mdparsegetpostdirection, NULL)
    ZEND_FE(mdparsegetsuffix, NULL)
    ZEND_FE(mdparsegetsuitename, NULL)
    ZEND_FE(mdparsegetsuitenumber, NULL)
    ZEND_FE(mdparsegetprivatemailboxnumber, NULL)
    ZEND_FE(mdparsegetprivatemailboxname, NULL)
    ZEND_FE(mdparsegetgarbage, NULL)
	/*********************************
	streetdatainterface
	*********************************/
	ZEND_FE(mdstreetcreate, NULL)
	ZEND_FE(mdstreetdestroy, NULL)

	/*setupmethods*/
	ZEND_FE(mdstreetinitialize, NULL)
	ZEND_FE(mdstreetgetinitializeerrorstring, NULL)
	ZEND_FE(mdstreetgetdatabasedate, NULL)
	ZEND_FE(mdstreetgetbuildnumber, NULL)
	ZEND_FE(mdstreetsetlicensestring, NULL)

	/*processingmethod*/
	ZEND_FE(mdstreetfindstreet, NULL)
	ZEND_FE(mdstreetfindstreetnext, NULL)
	ZEND_FE(mdstreetisaddressinrange, NULL)
	ZEND_FE(mdstreetisaddressinrange2, NULL)

	/*outputdata*/
	ZEND_FE(mdstreetgetbasealternateindicator, NULL)
	ZEND_FE(mdstreetgetlacsindicator, NULL)
	ZEND_FE(mdstreetgeturbanizationcode, NULL)
	ZEND_FE(mdstreetgetlastlinenumber, NULL)
	ZEND_FE(mdstreetgetaddresstype, NULL)
	ZEND_FE(mdstreetgetcongressionaldistrict, NULL)
	ZEND_FE(mdstreetgetcountyfips, NULL)
	ZEND_FE(mdstreetgetcarrierroute, NULL)
	ZEND_FE(mdstreetgetzip, NULL)
	ZEND_FE(mdstreetgetplus4high, NULL)
	ZEND_FE(mdstreetgetplus4low, NULL)
	ZEND_FE(mdstreetgetsuiterangeoddeven, NULL)
	ZEND_FE(mdstreetgetsuiterangehigh, NULL)
	ZEND_FE(mdstreetgetsuiterangelow, NULL)
	ZEND_FE(mdstreetgetsuitename, NULL)
	ZEND_FE(mdstreetgetpostdirection, NULL)
	ZEND_FE(mdstreetgetsuffix, NULL)
	ZEND_FE(mdstreetgetstreetname, NULL)
	ZEND_FE(mdstreetgetpredirection, NULL)
	ZEND_FE(mdstreetgetprimaryrangeoddeven, NULL)
	ZEND_FE(mdstreetgetprimaryrangehigh, NULL)
	ZEND_FE(mdstreetgetprimaryrangelow, NULL)
	ZEND_FE(mdstreetgetcompany, NULL)

	/*********************************
	zipcodedatainterface
	*********************************/
	ZEND_FE(mdzipcreate, NULL)
	ZEND_FE(mdzipdestroy, NULL)

	/*setupmethods*/
	ZEND_FE(mdzipinitialize, NULL)
	ZEND_FE(mdzipgetinitializeerrorstring, NULL)
	ZEND_FE(mdzipgetdatabasedate, NULL)
	ZEND_FE(mdzipgetbuildnumber, NULL)
	ZEND_FE(mdzipsetlicensestring, NULL)

	/*processingmethod*/
	ZEND_FE(mdzipfindzip, NULL)
	ZEND_FE(mdzipfindzipnext, NULL)
	ZEND_FE(mdzipfindzipincity, NULL)
	ZEND_FE(mdzipfindzipincitynext, NULL)
	ZEND_FE(mdzipfindcityinstate, NULL)
	ZEND_FE(mdzipfindcityinstatenext, NULL)
	ZEND_FE(mdzipcomputedistance, NULL)
	ZEND_FE(mdzipcomputebearing, NULL)

	/*outputdata*/
	ZEND_FE(mdzipgetcountynamefromfips, NULL)
	ZEND_FE(mdzipgetscfarea, NULL)
	ZEND_FE(mdzipgetzip, NULL)
	ZEND_FE(mdzipgetcity, NULL)
	ZEND_FE(mdzipgetcityabbreviation, NULL)
	ZEND_FE(mdzipgetstate, NULL)
	ZEND_FE(mdzipgetziptype, NULL)
	ZEND_FE(mdzipgetcountyname, NULL)
	ZEND_FE(mdzipgetcountyfips, NULL)
	ZEND_FE(mdzipgetareacode, NULL)
	ZEND_FE(mdzipgetlongitude, NULL)
	ZEND_FE(mdzipgetlatitude, NULL)
	ZEND_FE(mdzipgettimezone, NULL)
	ZEND_FE(mdzipgettimezonecode, NULL)
	ZEND_FE(mdzipgetmsa, NULL)
	ZEND_FE(mdzipgetpmsa, NULL)
	ZEND_FE(mdzipgetfacilitycode, NULL)
	ZEND_FE(mdzipgetlastlineindicator, NULL)
	ZEND_FE(mdzipgetlastlinenumber, NULL)
	ZEND_FE(mdzipgetpreferredlastlinenumber, NULL)
	ZEND_FE(mdzipgetautomation, NULL)
   	{NULL, NULL, NULL}
    
};

/* compiled module information */
zend_module_entry mdaddrphp_module_entry =
{
    STANDARD_MODULE_HEADER,
    "mdaddrPHP module",
    mdaddrphp_functions,
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL,
    NO_VERSION_YET,
    STANDARD_MODULE_PROPERTIES
};
/*It is called at load time of a module when a "dl()" is called from PHP script*/
ZEND_GET_MODULE(mdaddrphp)
/*Implementation of exported functions to be made avaiable to PHP */
/* setup methods */
ZEND_FUNCTION(mdaddrcreate)
{
	h=mdAddrCreate();
	
}

ZEND_FUNCTION(mdaddrdestroy)
{
 	mdAddrDestroy(h);
}

ZEND_FUNCTION(mdaddrinitialize)
{
     const char* param1;
     const char* param2;
     const char* param3;
     int len1;
     int len2;
     int len3;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sss", &param1,&len1,&param2,&len2,&param3,&len3) == FAILURE) {
        return;
    }
    	
	RETURN_LONG(mdAddrInitialize(h,param1,param2,param3));
}

ZEND_FUNCTION(mdaddrgetinitializeerrorstring)
{
     char  rs[255];
     strcpy(rs,mdAddrGetInitializeErrorString(h));
     RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrsetlicensestring)
{
    const char* param;
    int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
	RETURN_LONG(mdAddrSetLicenseString(h,param));
}

ZEND_FUNCTION(mdaddrgetbuildnumber)
{
    char  rs[255];
       strcpy(rs,mdAddrGetBuildNumber(h));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetdatabasedate)
{
    char  rs[255];  
    strcpy(rs,mdAddrGetDatabaseDate(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetrbdidatabasedate)
{
    char  rs[255];  
    strcpy(rs,mdAddrGetRBDIDatabaseDate(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetexpirationdate)
{
     char  rs[255];
     
     strcpy(rs,mdAddrGetExpirationDate(h));
     RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrsetpathtousfiles)
{
     const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
    mdAddrSetPathToUSFiles(h,param);
}

ZEND_FUNCTION(mdaddrsetpathtodpvdatafiles)
{
     const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
    mdAddrSetPathToDPVDataFiles(h,param);
}


ZEND_FUNCTION(mdaddrsetpathtolacslinkdatafiles)
{
     const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
    mdAddrSetPathToLACSLinkDataFiles(h,param);
}
ZEND_FUNCTION(mdaddrsetpathtorbdifiles)
{
     const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
    mdAddrSetPathToRBDIFiles(h,param);
}
ZEND_FUNCTION(mdaddrsetpathtocanadafiles)
{
     const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
    mdAddrSetPathToCanadaFiles(h,param);
}

ZEND_FUNCTION(mdaddrclearproperties)
{
	mdAddrClearProperties(h);
}

ZEND_FUNCTION(mdaddrinitializedatafiles)
{
    RETURN_LONG(mdAddrInitializeDataFiles(h));
}

ZEND_FUNCTION(mdaddrgetstatuscode)
{
    char rs[255];
	strcpy(rs,mdAddrGetStatusCode(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgeterrorcode)
{
    char rs[255];
	
	strcpy(rs,mdAddrGetErrorCode(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgeterrorstring)
{
    char rs[255];
	
	strcpy(rs,mdAddrGetErrorString(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrsetps3553_b1_processorname)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
    
	mdAddrSetPS3553_B1_ProcessorName(h,param);
}

ZEND_FUNCTION(mdaddrsetps3553_b4_listname)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
    
	mdAddrSetPS3553_B4_ListName(h,param);
}

ZEND_FUNCTION(mdaddrsetps3553_d3_name)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
    
	mdAddrSetPS3553_D3_Name(h,param);
}

ZEND_FUNCTION(mdaddrsetps3553_d3_company)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
    
	mdAddrSetPS3553_D3_Company(h,param);
}

ZEND_FUNCTION(mdaddrsetps3553_d3_address)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
    
	mdAddrSetPS3553_D3_Address(h,param);
}

ZEND_FUNCTION(mdaddrsetps3553_d3_city)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
    
	mdAddrSetPS3553_D3_City(h,param);
}

ZEND_FUNCTION(mdaddrsetps3553_d3_state)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
    
	mdAddrSetPS3553_D3_State(h,param);
}

ZEND_FUNCTION(mdaddrsetps3553_d3_zip)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
    
	mdAddrSetPS3553_D3_ZIP(h,param);
}

ZEND_FUNCTION(mdaddrgetformps3553)
{	
    char rs[255];	
	strcpy(rs,mdAddrGetFormPS3553(h));     	
	RETURN_STRING(rs,1);	
}

ZEND_FUNCTION(mdaddrsaveformps3553)
{
    const char* param;
     int len;
     int i=-1;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
    
	i=mdAddrSaveFormPS3553(h,param);
	RETURN_LONG(i);
}


ZEND_FUNCTION(mdaddrresetdpv)
{
    
	mdAddrResetDPV(h);
}

ZEND_FUNCTION(mdaddrresetformps3553)
{
    mdAddrResetFormPS3553(h);
}

ZEND_FUNCTION(mdaddrgetps3553_b6_totalrecords)
{
	RETURN_LONG(mdAddrGetPS3553_B6_TotalRecords(h));
}


ZEND_FUNCTION(mdaddrgetps3553_c1a_zip4coded)
{
    
	RETURN_LONG(mdAddrGetPS3553_C1a_ZIP4Coded(h));
}
ZEND_FUNCTION(mdaddrgetps3553_c1c_dpbcassigned)
{
	RETURN_LONG(mdAddrGetPS3553_C1c_DPBCAssigned(h));
}
ZEND_FUNCTION(mdaddrgetps3553_c1d_fivedigitcoded)
{
	RETURN_LONG(mdAddrGetPS3553_C1d_FiveDigitCoded(h));
}

ZEND_FUNCTION(mdaddrgetps3553_c1e_crrtcoded)
{
	RETURN_LONG(mdAddrGetPS3553_C1e_CRRTCoded(h));
}
ZEND_FUNCTION(mdaddrgetps3553_c1f_elotassigned)
{

	RETURN_LONG(mdAddrGetPS3553_C1e_CRRTCoded(h));
}
ZEND_FUNCTION(mdaddrgetps3553_e_highrisedefault)
{    
	RETURN_LONG(mdAddrGetPS3553_E_HighRiseDefault(h));
}

ZEND_FUNCTION(mdaddrgetps3553_e_highriseexact)
{    
	RETURN_LONG(mdAddrGetPS3553_E_HighRiseExact(h));
}
ZEND_FUNCTION(mdaddrgetps3553_e_ruralroutedefault)
{    
	RETURN_LONG(mdAddrGetPS3553_E_RuralRouteDefault(h));
}
ZEND_FUNCTION(mdaddrgetps3553_e_ruralrouteexact)
{
    
	RETURN_LONG(mdAddrGetPS3553_E_RuralRouteExact(h));
}
ZEND_FUNCTION(mdaddrgetps3553_e_lacscount)
{
    
	RETURN_LONG(mdAddrGetPS3553_E_LACSCount(h));
}
ZEND_FUNCTION(mdaddrgetps3553_e_ewscount)
{
    
	RETURN_LONG(mdAddrGetPS3553_E_EWSCount(h));
}
ZEND_FUNCTION(mdaddrgetps3553_e_dpvcount)
{
    
	RETURN_LONG(mdAddrGetPS3553_E_DPVCount(h));
}


ZEND_FUNCTION(mdaddrsetcompany)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
    
	mdAddrSetCompany(h,param);
}

ZEND_FUNCTION(mdaddrsetaddress)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
    
	mdAddrSetAddress(h,param);
}

ZEND_FUNCTION(mdaddrsetaddress2)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
    
	mdAddrSetAddress2(h,param);
}


ZEND_FUNCTION(mdaddrsetlastline)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
   
	mdAddrSetLastLine(h,param);
}

ZEND_FUNCTION(mdaddrsetsuite)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
   
	mdAddrSetSuite(h,param);
}

ZEND_FUNCTION(mdaddrsetcity)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
     
	mdAddrSetCity(h,param);
}

ZEND_FUNCTION(mdaddrsetstate)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
     	
	mdAddrSetState(h,param);
}

ZEND_FUNCTION(mdaddrsetzip)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
     	
	mdAddrSetZip(h,param);
}

ZEND_FUNCTION(mdaddrsetplus4)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
     
	mdAddrSetPlus4(h,param);
}

ZEND_FUNCTION(mdaddrseturbanization)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
     	
	mdAddrSetUrbanization(h,param);
}

ZEND_FUNCTION(mdaddrsetparsedaddressrange)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
     	
	mdAddrSetParsedAddressRange(h,param);
}

ZEND_FUNCTION(mdaddrsetparsedpredirection)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
     	
	mdAddrSetParsedPreDirection(h,param);
}

ZEND_FUNCTION(mdaddrsetparsedstreetname)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
     	
	mdAddrSetParsedStreetName(h,param);
}

ZEND_FUNCTION(mdaddrsetparsedsuffix)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
    
	mdAddrSetParsedSuffix(h,param);
}

ZEND_FUNCTION(mdaddrsetparsedpostdirection)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
     	
	mdAddrSetParsedPostDirection(h,param);
}

ZEND_FUNCTION(mdaddrsetparsedsuitename)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
     	
	mdAddrSetParsedSuiteName(h,param);
}

ZEND_FUNCTION(mdaddrsetparsedsuiterange)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
     	
	mdAddrSetParsedSuiteRange(h,param);
}

ZEND_FUNCTION(mdaddrsetcountrycode)
{
    const char* param;
     int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
     	
	mdAddrSetCountryCode(h,param);
}

ZEND_FUNCTION(mdaddrverifyaddress)
{
    	
	RETURN_LONG(mdAddrVerifyAddress(h));
}


ZEND_FUNCTION(mdaddrgetcompany)
{
    char rs[255];
	
	strcpy(rs,mdAddrGetCompany(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetaddress)
{	
	char rs[255];
    	
	strcpy(rs,mdAddrGetAddress(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetaddress2)
{	
	char rs[255];
    	
	strcpy(rs,mdAddrGetAddress2(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetsuite)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetSuite(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetcity)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetCity(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetcityabbreviation)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetCityAbbreviation(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetstate)
{	
	char rs[255];
    	
	strcpy(rs,mdAddrGetState(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetzip)
{
    	char rs[255];
	
	strcpy(rs,mdAddrGetZip(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetplus4)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetPlus4(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetcarrierroute)
{	
	char rs[255];
    	
	strcpy(rs,mdAddrGetCarrierRoute(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetdeliverypointcode)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetDeliveryPointCode(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetdeliverypointcheckdigit)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetDeliveryPointCheckDigit(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetcountyfips)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetCountyFips(h));
	RETURN_STRING(rs,1);
}
ZEND_FUNCTION(mdaddrgetcountyname)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetCountyName(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetaddresstypecode)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetAddressTypeCode(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetaddresstypestring)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetAddressTypeString(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgeturbanization)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetUrbanization(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetcongressionaldistrict)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetCongressionalDistrict(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetlacs)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetLACS(h));
	RETURN_STRING(rs,1);
}
ZEND_FUNCTION(mdaddrgetlacslinkindicator)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetLACSLinkIndicator(h));
	RETURN_STRING(rs,1);
}


ZEND_FUNCTION(mdaddrgetprivatemailbox)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetPrivateMailbox(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgettimezonecode)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetTimeZoneCode(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgettimezone)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetTimeZone(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetmsa)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetMsa(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetpmsa)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetPmsa(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetdefaultflagindicator)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetDefaultFlagIndicator(h));
	RETURN_STRING(rs,1);
}
ZEND_FUNCTION(mdaddrgetsuitestatus)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetSuiteStatus(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetewsflag)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetEWSFlag(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetcmra)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetCMRA(h));
	RETURN_STRING(rs,1);
}
ZEND_FUNCTION(mdaddrgetcountrycode)
{	
	char rs[255];
    	
	strcpy(rs,mdAddrGetCountryCode(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetziptype)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetZipType(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetfalsetable)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetFalseTable(h));
	RETURN_STRING(rs,1);
}
ZEND_FUNCTION(mdaddrgetdpvfootnotes)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetDPVFootnotes(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetlacslinkreturncode)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetLACSLinkReturnCode(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetrbdi)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetRBDI(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetparsedaddressrange)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetParsedAddressRange(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetparsedpredirection)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetParsedPreDirection(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetparsedstreetname)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetParsedStreetName(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetparsedsuffix)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetParsedSuffix(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetparsedpostdirection)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetParsedPostDirection(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetparsedsuitename)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetParsedSuiteName(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetparsedsuiterange)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetParsedSuiteRange(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetparsedprivatemailboxname)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetParsedPrivateMailboxName(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetparsedprivatemailboxnumber)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetParsedPrivateMailboxNumber(h));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdaddrgetparsedgarbage)
{
	char rs[255];
    	
	strcpy(rs,mdAddrGetParsedGarbage(h));
	RETURN_STRING(rs,1);
}


/*********************************
        Parse Interface
*********************************/

/*********************************
        Parse Interface
*********************************/
ZEND_FUNCTION(mdparsecreate)
{
      
	pa=mdParseCreate();
}

ZEND_FUNCTION(mdparsedestroy)
{
 	
	mdParseDestroy(pa);
	
}

ZEND_FUNCTION(mdparseinitialize)
{
     const char* param;
     int len;
   	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
		return;
    }
    	
	RETURN_LONG(mdParseInitialize(pa,param));
}

ZEND_FUNCTION(mdparsegetbuildnumber)
{
    char  rs[255];
       
	strcpy(rs,mdParseGetBuildNumber(pa));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdparseparse)
{
	const char* param;
  	int len;
   	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
		return;
   	}
  	
	mdParseParse(pa,param);
}

ZEND_FUNCTION(mdparseparsenext)
{
	RETURN_LONG(mdParseParseNext(pa));
}

ZEND_FUNCTION(mdparselastlineparse)
{
  	const char* param;
  	int len;
     	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       		return;
    	}
	
	mdParseLastLineParse(pa,param);
}

ZEND_FUNCTION(mdparsegetzip)
{
	char rs[255];
	
	strcpy(rs,mdParseGetZip(pa));
	RETURN_STRING(rs,1);
}
ZEND_FUNCTION(mdparsegetplus4)
{
	char rs[255];
	
	strcpy(rs,mdParseGetPlus4(pa));
	RETURN_STRING(rs,1);
}
ZEND_FUNCTION(mdparsegetcity)
{
	char rs[255];
	
	strcpy(rs,mdParseGetCity(pa));
	RETURN_STRING(rs,1);
}
ZEND_FUNCTION(mdparsegetstate)
{
	char rs[255];
	
	strcpy(rs,mdParseGetState(pa));
	RETURN_STRING(rs,1);
}
ZEND_FUNCTION(mdparsegetstreetname)
{
	char rs[255];
	
	strcpy(rs,mdParseGetStreetName(pa));
	RETURN_STRING(rs,1);
}
ZEND_FUNCTION(mdparsegetrange)
{
	char rs[255];
	
	strcpy(rs,mdParseGetRange(pa));
	RETURN_STRING(rs,1);
}
ZEND_FUNCTION(mdparsegetpredirection)
{
	char rs[255];
	
	strcpy(rs,mdParseGetPreDirection(pa));
	RETURN_STRING(rs,1);
}
ZEND_FUNCTION(mdparsegetpostdirection)
{
	char rs[255];
	
	strcpy(rs,mdParseGetPostDirection(pa));
	RETURN_STRING(rs,1);
}
ZEND_FUNCTION(mdparsegetsuffix)
{
	char rs[255];
	
	strcpy(rs,mdParseGetSuffix(pa));
	RETURN_STRING(rs,1);
}
ZEND_FUNCTION(mdparsegetsuitename)
{
	char rs[255];
	
	strcpy(rs,mdParseGetSuiteName(pa));
	RETURN_STRING(rs,1);
}
ZEND_FUNCTION(mdparsegetsuitenumber)
{
	char rs[255];
	
	strcpy(rs,mdParseGetSuiteNumber(pa));
	RETURN_STRING(rs,1);
}
ZEND_FUNCTION(mdparsegetprivatemailboxnumber)
{
	char rs[255];
	
	strcpy(rs,mdParseGetPrivateMailboxNumber(pa));
	RETURN_STRING(rs,1);
}
ZEND_FUNCTION(mdparsegetprivatemailboxname)
{
	char rs[255];
	
	strcpy(rs,mdParseGetPrivateMailboxName(pa));
	RETURN_STRING(rs,1);
}
ZEND_FUNCTION(mdparsegetgarbage)
{
	char rs[255];
	
	strcpy(rs,mdParseGetGarbage(pa));
	RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetcreate)
{
     
	s=mdStreetCreate();	
}

ZEND_FUNCTION(mdstreetdestroy)
{	
	mdStreetDestroy(s);
}

ZEND_FUNCTION(mdstreetinitialize)
{
     const char* param1;
     const char* param2;
     const char* param3;
     int len1;
     int len2;
     int len3;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sss", &param1,&len1,&param2,&len2,&param3,&len3) == FAILURE) {
        return;
    }
    
	RETURN_LONG(mdStreetInitialize(s,param1,param2,param3));	
}

ZEND_FUNCTION(mdstreetgetinitializeerrorstring)
{
     char  rs[255];
          
     strcpy(rs,mdStreetGetInitializeErrorString(s));
     RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgetdatabasedate)
{
     char  rs[255];
     
     strcpy(rs,mdStreetGetDatabaseDate(s));
     RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgetbuildnumber)
{
    char  rs[255];
   
       strcpy(rs,mdStreetGetBuildNumber(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetsetlicensestring)
{
    const char* param;
    int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
    
	RETURN_LONG(mdStreetSetLicenseString(s,param));
}

ZEND_FUNCTION(mdstreetfindstreet)
{
	const char* param1;
	const char* param2;
	int	            param3;
    	int len1;
	int len2;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ssl", &param1,&len1, &param2,&len2,&param3) == FAILURE) {
       return;
    }
    
	RETURN_LONG(mdStreetFindStreet(s,param1,param2,param3));
}
ZEND_FUNCTION(mdstreetfindstreetnext)
{
	RETURN_LONG(mdStreetFindStreetNext(s));
}
ZEND_FUNCTION(mdstreetisaddressinrange)
{
	const char* param1;
	const char* param2;
	const char* param3;
    	int len1;
	int len2;
	int len3;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sss", &param1,&len1, &param2,&len2,&param3,&len3) == FAILURE) {
       		return;
    	}
    	
	RETURN_LONG(mdStreetIsAddressInRange(s,param1,param2,param3));

}
ZEND_FUNCTION(mdstreetisaddressinrange2)
{
	const char* param1;
	const char* param2;
	const char* param3;
	const char* param4;
    	int len1;
	int len2;
	int len3;
	int len4;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ssss", &param1,&len1, &param2,&len2,&param3,&len3,&param4,&len4) == FAILURE) {
       		return;
    	}
    	
	RETURN_LONG(mdStreetIsAddressInRange2(s,param1,param2,param3,param4));
}

ZEND_FUNCTION(mdstreetgetbasealternateindicator)
{
	char  rs[255];
       strcpy(rs,mdStreetGetBaseAlternateIndicator(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgetlacsindicator)
{
	char  rs[255];
    
       strcpy(rs,mdStreetGetLACSIndicator(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgeturbanizationcode)
{
	char  rs[255];
    
       strcpy(rs,mdStreetGetUrbanizationCode(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgetlastlinenumber)
{
	char  rs[255];
    
       strcpy(rs,mdStreetGetLastLineNumber(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgetaddresstype)
{
	char  rs[255];
    
       strcpy(rs,mdStreetGetAddressType(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgetcongressionaldistrict)
{
	char  rs[255];
    
       strcpy(rs,mdStreetGetCongressionalDistrict(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgetcountyfips)
{
	char  rs[255];
    
       strcpy(rs,mdStreetGetCountyFips(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgetcarrierroute)
{
	char  rs[255];
    
       strcpy(rs,mdStreetGetCarrierRoute(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgetzip)
{
	char  rs[255];
    
       strcpy(rs,mdStreetGetZip(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgetplus4high)
{
	char  rs[255];
    
       strcpy(rs,mdStreetGetPlus4High(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgetplus4low)
{
	char  rs[255];
    
       strcpy(rs,mdStreetGetPlus4Low(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgetsuiterangeoddeven)
{
	char  rs[255];
    
       strcpy(rs,mdStreetGetSuiteRangeOddEven(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgetsuiterangehigh)
{
	char  rs[255];
    
       strcpy(rs,mdStreetGetSuiteRangeHigh(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgetsuiterangelow)
{
	char  rs[255];
    
       strcpy(rs,mdStreetGetSuiteRangeLow(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgetsuitename)
{
	char  rs[255];
    
       strcpy(rs,mdStreetGetSuiteName(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgetpostdirection)
{
	char  rs[255];
    
       strcpy(rs,mdStreetGetPostDirection(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgetsuffix)
{
	char  rs[255];
    
       strcpy(rs,mdStreetGetSuffix(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgetstreetname)
{
	char  rs[255];
    
       strcpy(rs,mdStreetGetStreetName(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgetpredirection)
{
	char  rs[255];
    
       strcpy(rs,mdStreetGetPreDirection(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgetprimaryrangeoddeven)
{
	char  rs[255];
    
       strcpy(rs,mdStreetGetPrimaryRangeOddEven(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgetprimaryrangehigh)
{
	char  rs[255];
    
       strcpy(rs,mdStreetGetPrimaryRangeHigh(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgetprimaryrangelow)
{
	char  rs[255];
    
       strcpy(rs,mdStreetGetPrimaryRangeLow(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdstreetgetcompany)
{
	char  rs[255];
    
       strcpy(rs,mdStreetGetCompany(s));
       RETURN_STRING(rs,1);
}

ZEND_FUNCTION(mdzipcreate)
{
	z=mdZipCreate();	
}

ZEND_FUNCTION(mdzipdestroy)
{
	mdZipDestroy(z);
}

ZEND_FUNCTION(mdzipinitialize)
{
     const char* param1;
     const char* param2;
     const char* param3;
     int len1;
     int len2;
     int len3;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sss", &param1,&len1,&param2,&len2,&param3,&len3) == FAILURE) {
        return;
    }
    
	RETURN_LONG(mdZipInitialize(z,param1,param2,param3));	
}
ZEND_FUNCTION(mdzipgetinitializeerrorstring)
{
	char  rs[255];
     
     strcpy(rs,mdZipGetInitializeErrorString(z));
     RETURN_STRING(rs,1);
}
ZEND_FUNCTION(mdzipgetdatabasedate)
{
     char  rs[255];
     
     strcpy(rs,mdZipGetDatabaseDate(z));
     RETURN_STRING(rs,1);
}
ZEND_FUNCTION(mdzipgetbuildnumber)
{
    char  rs[255];
       strcpy(rs,mdZipGetBuildNumber(z));
       RETURN_STRING(rs,1);
}
ZEND_FUNCTION(mdzipsetlicensestring)
{
    const char* param;
    int len;
     if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
    
	RETURN_LONG(mdZipSetLicenseString(z,param));
}

ZEND_FUNCTION(mdzipfindzip)
{
	const char* param1;
	int	            param2;
    	int len1;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sl", &param1,&len1, &param2) == FAILURE) {
       return;
    }
    
	RETURN_LONG(mdZipFindZip(z,param1,param2));
	
}
ZEND_FUNCTION(mdzipfindzipnext)
{
	RETURN_LONG(mdZipFindZipNext(z));
	
}
ZEND_FUNCTION(mdzipfindzipincity)
{
	const char* param1;
	const char* param2;
    	int len1;
	int len2;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &param1,&len1, &param2,&len2) == FAILURE) {
       return;
    }
    
	RETURN_LONG(mdZipFindZipInCity(z,param1,param2));
}
ZEND_FUNCTION(mdzipfindzipincitynext)
{
	 RETURN_LONG(mdZipFindZipInCityNext(z));
}
ZEND_FUNCTION(mdzipfindcityinstate)
{
	const char* param1;
	const char* param2;
    	int len1;
	int len2;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &param1,&len1, &param2,&len2) == FAILURE) {
       return;
    }
    
	RETURN_LONG(mdZipFindCityInState(z,param1,param2));
}
ZEND_FUNCTION(mdzipfindcityinstatenext)
{
	RETURN_LONG(mdZipFindCityInStateNext(z));
}
ZEND_FUNCTION(mdzipcomputedistance)
{
	double param1;
	double param2;
    	double param3;
	double param4;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dddd", &param1,&param2, &param3,&param4) == FAILURE) {
       return;
    }
    
	RETURN_DOUBLE(mdZipComputeDistance(z,param1,param2,param3,param4));

}
ZEND_FUNCTION(mdzipcomputebearing)
{
	double param1;
	double param2;
    	double param3;
	double param4;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dddd", &param1,&param2, &param3,&param4) == FAILURE) {
       return;
    }
    
	RETURN_DOUBLE(mdZipComputeBearing(z,param1,param2,param3,param4));
	
}

ZEND_FUNCTION(mdzipgetcountynamefromfips)
{
    const char* param;
    int len;
    char  rs[255];
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param,&len) == FAILURE) {
       return;
    }
    
       strcpy(rs,mdZipGetCountyNameFromFips(z,param));
       RETURN_STRING(rs,1);

}
ZEND_FUNCTION(mdzipgetscfarea)
{
    const char* param1;
    float* param2;
    float* param3;
    float* param4;
    float* param5;
    int len;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sdddd", &param1,&len,&param2,&param3,&param4,&param5) == FAILURE) {
       return;
    }
	
	
	RETURN_LONG(mdZipGetSCFArea(z,param1,param2,param3,param4,param5));
}

ZEND_FUNCTION(mdzipgetzip)
{
    char  rs[255];
    
       strcpy(rs,mdZipGetZip(z));
       RETURN_STRING(rs,1);

}
ZEND_FUNCTION(mdzipgetcity)
{
    char  rs[255];
    
       strcpy(rs,mdZipGetCity(z));
       RETURN_STRING(rs,1);

}
ZEND_FUNCTION(mdzipgetcityabbreviation)
{
    char  rs[255];
    
       strcpy(rs,mdZipGetCityAbbreviation(z));
       RETURN_STRING(rs,1);

}
ZEND_FUNCTION(mdzipgetstate)
{
    char  rs[255];
    
       strcpy(rs,mdZipGetState(z));
       RETURN_STRING(rs,1);

}
ZEND_FUNCTION(mdzipgetziptype)
{
    char  rs[255];
    
       strcpy(rs,mdZipGetZipType(z));
       RETURN_STRING(rs,1);

}
ZEND_FUNCTION(mdzipgetcountyname)
{
    char  rs[255];
    
       strcpy(rs,mdZipGetCountyName(z));
       RETURN_STRING(rs,1);

}
ZEND_FUNCTION(mdzipgetcountyfips)
{
    char  rs[255];
    
       strcpy(rs,mdZipGetCountyFips(z));
       RETURN_STRING(rs,1);

}
ZEND_FUNCTION(mdzipgetareacode)
{
    char  rs[255];
    
       strcpy(rs,mdZipGetAreaCode(z));
       RETURN_STRING(rs,1);

}
ZEND_FUNCTION(mdzipgetlongitude)
{
    char  rs[255];
    
       strcpy(rs,mdZipGetLongitude(z));
       RETURN_STRING(rs,1);

}
ZEND_FUNCTION(mdzipgetlatitude)
{
    char  rs[255];
    
       strcpy(rs,mdZipGetLatitude(z));
       RETURN_STRING(rs,1);

}
ZEND_FUNCTION(mdzipgettimezone)
{
    char  rs[255];
    
       strcpy(rs,mdZipGetTimeZone(z));
       RETURN_STRING(rs,1);

}
ZEND_FUNCTION(mdzipgettimezonecode)
{
    char  rs[255];
    
       strcpy(rs,mdZipGetTimeZoneCode(z));
       RETURN_STRING(rs,1);

}
ZEND_FUNCTION(mdzipgetmsa)
{
    char  rs[255];
    
       strcpy(rs,mdZipGetMsa(z));
       RETURN_STRING(rs,1);

}
ZEND_FUNCTION(mdzipgetpmsa)
{
    char  rs[255];
    
       strcpy(rs,mdZipGetPmsa(z));
       RETURN_STRING(rs,1);

}
ZEND_FUNCTION(mdzipgetfacilitycode)
{
    char  rs[255];
    
       strcpy(rs,mdZipGetFacilityCode(z));
       RETURN_STRING(rs,1);

}
ZEND_FUNCTION(mdzipgetlastlineindicator)
{
    char  rs[255];
    
       strcpy(rs,mdZipGetLastLineIndicator(z));
       RETURN_STRING(rs,1);

}
ZEND_FUNCTION(mdzipgetlastlinenumber)
{
    char  rs[255];
    
       strcpy(rs,mdZipGetLastLineNumber(z));
       RETURN_STRING(rs,1);

}
ZEND_FUNCTION(mdzipgetpreferredlastlinenumber)
{
    char  rs[255];
    
       strcpy(rs,mdZipGetPreferredLastLineNumber(z));
       RETURN_STRING(rs,1);

}
ZEND_FUNCTION(mdzipgetautomation)
{
    char  rs[255];
    
       strcpy(rs,mdZipGetAutomation(z));
       RETURN_STRING(rs,1);
}


