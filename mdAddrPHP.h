#include "mdAddr.h"
#include "mdEnums.h"

mdAddr	 	h;
mdParse		pa;
mdStreet	s;
mdZip		z;

/* declaration of functions to be exported */
ZEND_FUNCTION(mdaddrcreate);
ZEND_FUNCTION(mdaddrdestroy);

/*setupmethods*/
ZEND_FUNCTION(mdaddrinitialize);
ZEND_FUNCTION(mdaddrgetinitializeerrorstring);
ZEND_FUNCTION(mdaddrsetlicensestring);
ZEND_FUNCTION(mdaddrgetbuildnumber);
ZEND_FUNCTION(mdaddrgetdatabasedate);
ZEND_FUNCTION(mdaddrgetexpirationdate);
ZEND_FUNCTION(mdaddrsetpathtousfiles);
ZEND_FUNCTION(mdaddrsetpathtodpvdatafiles);
ZEND_FUNCTION(mdaddrsetpathtolacslinkdatafiles);
ZEND_FUNCTION(mdaddrsetpathtorbdifiles);
ZEND_FUNCTION(mdaddrsetpathtocanadafiles);
ZEND_FUNCTION(mdaddrclearproperties);
ZEND_FUNCTION(mdaddrinitializedatafiles);
ZEND_FUNCTION(mdaddrgetrbdidatabasedate);


/*errorsandstatus*/
ZEND_FUNCTION(mdaddrgetstatuscode);
ZEND_FUNCTION(mdaddrgeterrorcode);
ZEND_FUNCTION(mdaddrgeterrorstring);


/*cassform3553methods*/
ZEND_FUNCTION(mdaddrsetps3553_b1_processorname);
ZEND_FUNCTION(mdaddrsetps3553_b4_listname);
ZEND_FUNCTION(mdaddrsetps3553_d3_name);
ZEND_FUNCTION(mdaddrsetps3553_d3_company);
ZEND_FUNCTION(mdaddrsetps3553_d3_address);
ZEND_FUNCTION(mdaddrsetps3553_d3_city);
ZEND_FUNCTION(mdaddrsetps3553_d3_state);
ZEND_FUNCTION(mdaddrsetps3553_d3_zip);
ZEND_FUNCTION(mdaddrgetformps3553);
ZEND_FUNCTION(mdaddrsaveformps3553);
ZEND_FUNCTION(mdaddrresetformps3553);
ZEND_FUNCTION(mdaddrresetdpv);

/* Form PS3553 fields */
ZEND_FUNCTION(mdaddrgetps3553_b6_totalrecords);
ZEND_FUNCTION(mdaddrgetps3553_c1a_zip4coded);
ZEND_FUNCTION(mdaddrgetps3553_c1c_dpbcassigned);
ZEND_FUNCTION(mdaddrgetps3553_c1d_fivedigitcoded);
ZEND_FUNCTION(mdaddrgetps3553_c1e_crrtcoded);
ZEND_FUNCTION(mdaddrgetps3553_c1f_elotassigned);
ZEND_FUNCTION(mdaddrgetps3553_e_highrisedefault);
ZEND_FUNCTION(mdaddrgetps3553_e_highriseexact);
ZEND_FUNCTION(mdaddrgetps3553_e_ruralroutedefault);
ZEND_FUNCTION(mdaddrgetps3553_e_ruralrouteexact);
ZEND_FUNCTION(mdaddrgetps3553_e_lacscount);
ZEND_FUNCTION(mdaddrgetps3553_e_ewscount);
ZEND_FUNCTION(mdaddrgetps3553_e_dpvcount);

/*requiredinput*/
ZEND_FUNCTION(mdaddrsetcompany);
ZEND_FUNCTION(mdaddrsetaddress);
ZEND_FUNCTION(mdaddrsetaddress2);
ZEND_FUNCTION(mdaddrsetlastline);
ZEND_FUNCTION(mdaddrsetsuite);
ZEND_FUNCTION(mdaddrsetcity);
ZEND_FUNCTION(mdaddrsetstate);
ZEND_FUNCTION(mdaddrsetzip);
ZEND_FUNCTION(mdaddrsetplus4);
ZEND_FUNCTION(mdaddrseturbanization);

/*Optionalinput*/
ZEND_FUNCTION(mdaddrsetparsedaddressrange);
ZEND_FUNCTION(mdaddrsetparsedpredirection);
ZEND_FUNCTION(mdaddrsetparsedstreetname);
ZEND_FUNCTION(mdaddrsetparsedsuffix);
ZEND_FUNCTION(mdaddrsetparsedpostdirection);
ZEND_FUNCTION(mdaddrsetparsedsuitename);
ZEND_FUNCTION(mdaddrsetparsedsuiterange);
ZEND_FUNCTION(mdaddrsetcountrycode);

/*processingmethod*/
ZEND_FUNCTION(mdaddrverifyaddress);

/*Outputdata*/
ZEND_FUNCTION(mdaddrgetcompany);
ZEND_FUNCTION(mdaddrgetaddress);
ZEND_FUNCTION(mdaddrgetaddress2);
ZEND_FUNCTION(mdaddrgetsuite);
ZEND_FUNCTION(mdaddrgetcity);
ZEND_FUNCTION(mdaddrgetcityabbreviation);
ZEND_FUNCTION(mdaddrgetstate);
ZEND_FUNCTION(mdaddrgetzip);
ZEND_FUNCTION(mdaddrgetplus4);
ZEND_FUNCTION(mdaddrgetcarrierroute);
ZEND_FUNCTION(mdaddrgetdeliverypointcode);
ZEND_FUNCTION(mdaddrgetdeliverypointcheckdigit);
ZEND_FUNCTION(mdaddrgetcountyfips);
ZEND_FUNCTION(mdaddrgetcountyname);
ZEND_FUNCTION(mdaddrgetaddresstypecode);
ZEND_FUNCTION(mdaddrgetaddresstypestring);
ZEND_FUNCTION(mdaddrgeturbanization);
ZEND_FUNCTION(mdaddrgetcongressionaldistrict);
ZEND_FUNCTION(mdaddrgetlacs);
ZEND_FUNCTION(mdaddrgetlacslinkindicator);
ZEND_FUNCTION(mdaddrgetprivatemailbox);
ZEND_FUNCTION(mdaddrgettimezonecode);
ZEND_FUNCTION(mdaddrgettimezone);
ZEND_FUNCTION(mdaddrgetmsa);
ZEND_FUNCTION(mdaddrgetpmsa);
ZEND_FUNCTION(mdaddrgetdefaultflagindicator);
ZEND_FUNCTION(mdaddrgetsuitestatus);
ZEND_FUNCTION(mdaddrgetewsflag);
ZEND_FUNCTION(mdaddrgetcmra);
ZEND_FUNCTION(mdaddrgetcountrycode);
ZEND_FUNCTION(mdaddrgetziptype);
ZEND_FUNCTION(mdaddrgetfalsetable);
ZEND_FUNCTION(mdaddrgetdpvfootnotes);
ZEND_FUNCTION(mdaddrgetlacslinkreturncode);
ZEND_FUNCTION(mdaddrgetrbdi);

/*parsedinputdata*/
ZEND_FUNCTION(mdaddrgetparsedaddressrange);
ZEND_FUNCTION(mdaddrgetparsedpredirection);
ZEND_FUNCTION(mdaddrgetparsedstreetname);
ZEND_FUNCTION(mdaddrgetparsedsuffix);
ZEND_FUNCTION(mdaddrgetparsedpostdirection);
ZEND_FUNCTION(mdaddrgetparsedsuitename);
ZEND_FUNCTION(mdaddrgetparsedsuiterange);
ZEND_FUNCTION(mdaddrgetparsedprivatemailboxname);
ZEND_FUNCTION(mdaddrgetparsedprivatemailboxnumber);
ZEND_FUNCTION(mdaddrgetparsedgarbage);

/*********************************
        Parse Interface
*********************************/
ZEND_FUNCTION(mdparsecreate);
ZEND_FUNCTION(mdparsedestroy);

/* Setup methods */
ZEND_FUNCTION(mdparseinitialize);
ZEND_FUNCTION(mdparsegetbuildnumber);

/* Processing method */
ZEND_FUNCTION(mdparseparse);
ZEND_FUNCTION(mdparseparsenext);
ZEND_FUNCTION(mdparselastlineparse);

/* Output data */
ZEND_FUNCTION(mdparsegetzip);
ZEND_FUNCTION(mdparsegetplus4);
ZEND_FUNCTION(mdparsegetcity);
ZEND_FUNCTION(mdparsegetstate);
ZEND_FUNCTION(mdparsegetstreetname);
ZEND_FUNCTION(mdparsegetrange);
ZEND_FUNCTION(mdparsegetpredirection);
ZEND_FUNCTION(mdparsegetpostdirection);
ZEND_FUNCTION(mdparsegetsuffix);
ZEND_FUNCTION(mdparsegetsuitename);
ZEND_FUNCTION(mdparsegetsuitenumber);
ZEND_FUNCTION(mdparsegetprivatemailboxnumber);
ZEND_FUNCTION(mdparsegetprivatemailboxname);
ZEND_FUNCTION(mdparsegetgarbage);

/*********************************
streetdatainterface
*********************************/
ZEND_FUNCTION(mdstreetcreate);
ZEND_FUNCTION(mdstreetdestroy);

/*setupmethods*/
ZEND_FUNCTION(mdstreetinitialize);
ZEND_FUNCTION(mdstreetgetinitializeerrorstring);
ZEND_FUNCTION(mdstreetgetdatabasedate);
ZEND_FUNCTION(mdstreetgetbuildnumber);
ZEND_FUNCTION(mdstreetsetlicensestring);

/*processingmethod*/
ZEND_FUNCTION(mdstreetfindstreet);
ZEND_FUNCTION(mdstreetfindstreetnext);
ZEND_FUNCTION(mdstreetisaddressinrange);
ZEND_FUNCTION(mdstreetisaddressinrange2);

/*outputdata*/
ZEND_FUNCTION(mdstreetgetbasealternateindicator);
ZEND_FUNCTION(mdstreetgetlacsindicator);
ZEND_FUNCTION(mdstreetgeturbanizationcode);
ZEND_FUNCTION(mdstreetgetlastlinenumber);
ZEND_FUNCTION(mdstreetgetaddresstype);
ZEND_FUNCTION(mdstreetgetcongressionaldistrict);
ZEND_FUNCTION(mdstreetgetcountyfips);
ZEND_FUNCTION(mdstreetgetcarrierroute);
ZEND_FUNCTION(mdstreetgetzip);
ZEND_FUNCTION(mdstreetgetplus4high);
ZEND_FUNCTION(mdstreetgetplus4low);
ZEND_FUNCTION(mdstreetgetsuiterangeoddeven);
ZEND_FUNCTION(mdstreetgetsuiterangehigh);
ZEND_FUNCTION(mdstreetgetsuiterangelow);
ZEND_FUNCTION(mdstreetgetsuitename);
ZEND_FUNCTION(mdstreetgetpostdirection);
ZEND_FUNCTION(mdstreetgetsuffix);
ZEND_FUNCTION(mdstreetgetstreetname);
ZEND_FUNCTION(mdstreetgetpredirection);
ZEND_FUNCTION(mdstreetgetprimaryrangeoddeven);
ZEND_FUNCTION(mdstreetgetprimaryrangehigh);
ZEND_FUNCTION(mdstreetgetprimaryrangelow);
ZEND_FUNCTION(mdstreetgetcompany);

/*********************************
zipcodedatainterface
*********************************/
ZEND_FUNCTION(mdzipcreate);
ZEND_FUNCTION(mdzipdestroy);

/*setupmethods*/
ZEND_FUNCTION(mdzipinitialize);
ZEND_FUNCTION(mdzipgetinitializeerrorstring);
ZEND_FUNCTION(mdzipgetdatabasedate);
ZEND_FUNCTION(mdzipgetbuildnumber);
ZEND_FUNCTION(mdzipsetlicensestring);

/*processingmethod*/
ZEND_FUNCTION(mdzipfindzip);
ZEND_FUNCTION(mdzipfindzipnext);
ZEND_FUNCTION(mdzipfindzipincity);
ZEND_FUNCTION(mdzipfindzipincitynext);
ZEND_FUNCTION(mdzipfindcityinstate);
ZEND_FUNCTION(mdzipfindcityinstatenext);
ZEND_FUNCTION(mdzipcomputedistance);
ZEND_FUNCTION(mdzipcomputebearing);

/*outputdata*/
ZEND_FUNCTION(mdzipgetcountynamefromfips);
ZEND_FUNCTION(mdzipgetscfarea);
ZEND_FUNCTION(mdzipgetzip);
ZEND_FUNCTION(mdzipgetcity);
ZEND_FUNCTION(mdzipgetcityabbreviation);
ZEND_FUNCTION(mdzipgetstate);
ZEND_FUNCTION(mdzipgetziptype);
ZEND_FUNCTION(mdzipgetcountyname);
ZEND_FUNCTION(mdzipgetcountyfips);
ZEND_FUNCTION(mdzipgetareacode);
ZEND_FUNCTION(mdzipgetlongitude);
ZEND_FUNCTION(mdzipgetlatitude);
ZEND_FUNCTION(mdzipgettimezone);
ZEND_FUNCTION(mdzipgettimezonecode);
ZEND_FUNCTION(mdzipgetmsa);
ZEND_FUNCTION(mdzipgetpmsa);
ZEND_FUNCTION(mdzipgetfacilitycode);
ZEND_FUNCTION(mdzipgetlastlineindicator);
ZEND_FUNCTION(mdzipgetlastlinenumber);
ZEND_FUNCTION(mdzipgetpreferredlastlinenumber);
ZEND_FUNCTION(mdzipgetautomation);

