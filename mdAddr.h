/*
 * Melissa Data Address Object for Windows/Linux/Solaris
 * Copyright 1993-2005 Melissa Data Corporation.
 *
 * Public interface
 *
 * PRELIMINARY VERSION SUBJECT TO CHANGES
 */
#ifndef MDADDR_H
#define MDADDR_H

#ifndef MDAPI
#if defined(_WIN32) || defined(_WIN64)
#define MDAPI __declspec(dllimport)
#else
#define MDAPI
#endif
#endif

/*
 * C++ version of interface
 */
#if defined(__cplusplus) && !defined(MDCFORCE)

//
// Address Check Interface
//
class MDAPI mdAddr
{
protected:
	struct mdAddr_ *I;
private:	/* disable implicit constructor and assignment */
	mdAddr(mdAddr &x);
	mdAddr& operator=(mdAddr &x);
public:
	#undef MDENUMS_H
	#include "mdEnums.h"
	mdAddr();
	~mdAddr();

	/* Setup methods */
	enum ProgramStatus Initialize(const char*,const char*,const char*);
	enum ProgramStatus InitializeDataFiles();
	const char* GetInitializeErrorString();
	bool        SetLicenseString(const char*);
	const char* GetBuildNumber();
	const char* GetDatabaseDate();
	const char* GetExpirationDate();
	const char* GetLicenseExpirationDate();
	const char* GetCanadianDatabaseDate();
	const char* GetCanadianExpirationDate();

	void        SetPathToUSFiles(const char*);
	void        SetPathToCanadaFiles(const char*);
	void        SetPathToDPVDataFiles(const char*);
	void        SetPathToLACSLinkDataFiles(const char*);
	void        SetPathToSuiteLinkDataFiles(const char*);
	void        SetPathToSuiteFinderDataFiles(const char*);
	void        SetPathToRBDIFiles(const char*);
	const char* GetRBDIDatabaseDate();
	void        ClearProperties();
	void        ResetDPV();
	void        SetCASSEnable(int);
	void        SetUseUSPSPreferredCityNames(int);
	void        SetDiacritics(enum DiacriticsMode);

	/* Errors and status */
	const char* GetStatusCode();
	const char* GetErrorCode();
	const char* GetErrorString();
	const char* GetResults();

	/* Form PS3553 (CASS) methods */
	void        SetPS3553_B1_ProcessorName(const char*);
	void        SetPS3553_B4_ListName(const char*);
	void        SetPS3553_D3_Name(const char*);
	void        SetPS3553_D3_Company(const char*);
	void        SetPS3553_D3_Address(const char*);
	void        SetPS3553_D3_City(const char*);
	void        SetPS3553_D3_State(const char*);
	void        SetPS3553_D3_ZIP(const char*);
	const char* GetFormPS3553();
	bool        SaveFormPS3553(const char*);
	void        ResetFormPS3553();
	void		SetStandardizationType(StandardizeMode mode);

	/* SOA Form methods */
	const char* GetFormSOA();
	void        SaveFormSOA(const char *);
	void        ResetFormSOA();
        void        SetSOACustomerInfo(const char *customerName,
                                       const char * customerAddress);
        void        SetSOACPCNumber(const char * CPCNumber);
        const char* GetSOACustomerInfo();
        const char* GetSOACPCNumber();
        long        GetSOATotalRecords();
        float       GetSOAAAPercentage();
        const char* GetSOAAAExpiryDate();
        const char* GetSOASoftwareInfo();
        const char* GetSOAErrorString();

	/* Required input */
	void        SetCompany(const char*);
	void        SetLastName(const char*);
	void        SetAddress(const char*);
	void        SetAddress2(const char*);
	void        SetLastLine(const char*);
	void        SetSuite(const char*);
	void        SetCity(const char*);
	void        SetState(const char*);
	void        SetZip(const char*);
	void        SetPlus4(const char*);
	void        SetUrbanization(const char*);

	/* Optional Input */
	void        SetParsedAddressRange(const char*);
	void        SetParsedPreDirection(const char*);
	void        SetParsedStreetName(const char*);
	void        SetParsedSuffix(const char*);
	void        SetParsedPostDirection(const char*);
	void        SetParsedSuiteName(const char*);
	void        SetParsedSuiteRange(const char*);
	void        SetParsedRouteService(const char*);         /* Canada only */
	void        SetParsedLockBox(const char*);              /* Canada only */
	void        SetParsedDeliveryInstallation(const char*); /* Canada only */

	void        SetCountryCode(const char*);

	/* Processing method */
	bool        VerifyAddress();

	/* Output data */
	const char* GetCompany();
	const char* GetLastName();
	const char* GetAddress();
	const char* GetAddress2();
	const char* GetSuite();
	const char* GetCity();
	const char* GetCityAbbreviation();
	const char* GetState();
	const char* GetZip();
	const char* GetPlus4();
	const char* GetCarrierRoute();
	const char* GetDeliveryPointCode();
	const char* GetDeliveryPointCheckDigit();
	const char* GetCountyFips();
	const char* GetCountyName();
	const char* GetAddressTypeCode();
	const char* GetAddressTypeString();
	const char* GetUrbanization();
	const char* GetCongressionalDistrict();
	const char* GetLACS();
	const char* GetLACSLinkIndicator();
	const char* GetPrivateMailbox();
	const char* GetTimeZoneCode();
	const char* GetTimeZone();
	const char* GetMsa();
	const char* GetPmsa();
	const char* GetDefaultFlagIndicator();
	const char* GetSuiteStatus();
	const char* GetEWSFlag();
	const char* GetCMRA();
	const char* GetDsfNoStats();
	const char* GetDsfVacant();
	const char* GetCountryCode();
	const char* GetZipType();
	const char* GetFalseTable();
	const char* GetDPVFootnotes();
	const char* GetLACSLinkReturnCode();
	const char* GetSuiteLinkReturnCode();
	const char* GetRBDI();
	const char* GetELotNumber();
	const char* GetELotOrder();
	const char* GetAddressKey();
	bool FindSuggestion();
	bool FindSuggestionNext();

	/* Form PS3553 fields */
	int         GetPS3553_B6_TotalRecords();
	int         GetPS3553_C1a_ZIP4Coded();
	int         GetPS3553_C1c_DPBCAssigned();
	int         GetPS3553_C1d_FiveDigitCoded();
	int         GetPS3553_C1e_CRRTCoded();
	int         GetPS3553_C1f_eLOTAssigned();
	int         GetPS3553_E_HighRiseDefault();
	int         GetPS3553_E_HighRiseExact();
	int         GetPS3553_E_RuralRouteDefault();
	int         GetPS3553_E_RuralRouteExact();
	int         GetPS3553_E_LACSCount();
	int         GetPS3553_E_EWSCount();
	int         GetPS3553_E_DPVCount();

	/* Future Form PS3553 fields */
	int         GetPS3553_X_POBoxCount();
	int         GetPS3553_X_HCExactCount();
	int         GetPS3553_X_FirmCount();
	int         GetPS3553_X_GenDeliveryCount();
	int         GetPS3553_X_MilitaryZipCount();
	int         GetPS3553_X_NonDeliveryCount();
	int         GetPS3553_X_StreetCount();
	int         GetPS3553_X_HCDefaultCount();
	int         GetPS3553_X_OtherCount();
	int         GetPS3553_X_LacsLinkCodeACount();
	int         GetPS3553_X_LacsLinkCode00Count();
	int         GetPS3553_X_LacsLinkCode14Count();
	int         GetPS3553_X_LacsLinkCode92Count();
	int         GetPS3553_X_LacsLinkCode09Count();
	int         GetPS3553_X_SuiteLinkCodeACount();
	int         GetPS3553_X_SuiteLinkCode00Count();


	/* Parsed input data */
	const char* GetParsedAddressRange();
	const char* GetParsedPreDirection();
	const char* GetParsedStreetName();
	const char* GetParsedSuffix();
	const char* GetParsedPostDirection();
	const char* GetParsedSuiteName();
	const char* GetParsedSuiteRange();
	const char* GetParsedPrivateMailboxName();
	const char* GetParsedPrivateMailboxNumber();
	const char* GetParsedGarbage();
	const char* GetParsedRouteService();         /* Canada only */
	const char* GetParsedLockBox();              /* Canada only */
	const char* GetParsedDeliveryInstallation(); /* Canada only */

	/* Reserved for Melissa DATA use */
	void        SetReserved(const char*, const char*);
	const char* GetReserved(const char*);
};

//
// Parse Interface
//
class MDAPI mdParse
{
protected:
	struct mdParse_ *I;
private: /* disable implicit constructor and assignment */
	mdParse(mdParse &x);
	mdParse &operator=(mdParse &x);
public:
	#undef MDENUMS_H
	#include "mdEnums.h"
	mdParse();
	~mdParse();

	// Setup methods
	enum ProgramStatus Initialize(const char*);
	const char* GetBuildNumber();

	// Processing method
	void        Parse(const char*);
	void        ParseCanadian(const char*);
	bool        ParseNext();
	void        LastLineParse(const char*);

	// Output data
	const char* GetZip();
	const char* GetPlus4();
	const char* GetCity();
	const char* GetState();
	const char* GetStreetName();
	const char* GetRange();
	const char* GetPreDirection();
	const char* GetPostDirection();
	const char* GetSuffix();
	const char* GetSuiteName();
	const char* GetSuiteNumber();
	const char* GetPrivateMailboxNumber();
	const char* GetPrivateMailboxName();
	const char* GetGarbage();
	const char* GetRouteService();         /* Canada only */
	const char* GetLockBox();              /* Canada only */
	const char* GetDeliveryInstallation(); /* Canada only */

	int ParseRule();
};

//
// Street Data Interface
//
class MDAPI mdStreet
{
protected:
	struct mdStreet_ *I;
private: /* disable implicit constructor and assignment */
	mdStreet(mdStreet &x);
	mdStreet &operator=(const mdStreet &x);
public:
	#undef MDENUMS_H
	#include "mdEnums.h"
	mdStreet();
	~mdStreet();

	// Setup methods
	enum ProgramStatus Initialize(const char*, const char*, const char*);
	const char* GetInitializeErrorString();
	const char* GetDatabaseDate();
	const char* GetBuildNumber();
	bool        SetLicenseString(const char*);
	const char* GetLicenseExpirationDate();

	// Processing method
	bool        FindStreet(const char*, const char*, bool);
	bool        FindStreetNext();
	bool        IsAddressInRange(const char*, const char*, const char*);
	bool        IsAddressInRange2(const char*, const char*, const char*, const char*);

	// Output data
	const char* GetBaseAlternateIndicator();
	const char* GetLACSIndicator();
	const char* GetUrbanizationCode();
	const char* GetUrbanizationName();
	const char* GetLastLineNumber();
	const char* GetAddressType();
	const char* GetCongressionalDistrict();
	const char* GetCountyFips();
	const char* GetCompany();
	const char* GetCarrierRoute();
	const char* GetZip();
	const char* GetDeliveryInstallation();
	const char* GetPlus4High();
	const char* GetPlus4Low();
	const char* GetSuiteRangeOddEven();
	const char* GetSuiteRangeHigh();
	const char* GetSuiteRangeLow();
	const char* GetSuiteName();
	const char* GetPostDirection();
	const char* GetSuffix();
	const char* GetStreetName();
	const char* GetPreDirection();
	const char* GetPrimaryRangeOddEven();
	const char* GetPrimaryRangeHigh();
	const char* GetPrimaryRangeLow();
};

//
// Zip Code Data Interface
//
class MDAPI mdZip
{
protected:
	struct mdZip_ *I;
private: /* disable implicit constructor and assignment */
	mdZip(mdZip &x);
	mdZip& operator=(mdZip &x);
public:
	#undef MDENUMS_H
	#include "mdEnums.h"
	mdZip();
	~mdZip();

	// Setup methods
	enum ProgramStatus Initialize(const char*, const char*, const char*);
	const char* GetInitializeErrorString();
	const char* GetDatabaseDate();
	const char* GetBuildNumber();
	bool        SetLicenseString(const char*);
	const char* GetLicenseExpirationDate();

	// Processing methods
	bool        FindZip(const char*, bool);
	bool        FindZipNext();
	bool        FindZipInCity(const char*, const char*);
	bool        FindZipInCityNext();
	bool        FindCityInState(const char*, const char*);
	bool        FindCityInStateNext();
	double      ComputeDistance(double, double, double, double);
	double      ComputeBearing(double, double, double, double);

	// Output data
	const char* GetCountyNameFromFips(const char*);
	int         GetSCFArea(const char*, float*, float*, float*, float*);
	const char* GetZip();
	const char* GetCity();
	const char* GetCityAbbreviation();
	const char* GetState();
	const char* GetZipType();
	const char* GetCountyName();
	const char* GetCountyFips();
	const char* GetAreaCode();
	const char* GetLongitude();
	const char* GetLatitude();
	const char* GetTimeZone();
	const char* GetTimeZoneCode();
	const char* GetMsa();
	const char* GetPmsa();
	const char* GetFacilityCode();
	const char* GetLastLineIndicator();
	const char* GetLastLineNumber();
	const char* GetPreferredLastLineNumber();
	const char* GetAutomation();
	const char* GetFinanceNumber();

};

#else

/*
 * C version of interface
 */
#include "mdEnums.h"

typedef struct mdAddr_ *mdAddr;

MDAPI mdAddr      mdAddrCreate(void);
MDAPI void        mdAddrDestroy(mdAddr);

/* Setup methods */
MDAPI enum mdProgramStatus mdAddrInitialize(mdAddr, const char*, const char*, const char*);
MDAPI enum mdProgramStatus mdAddrInitializeDataFiles(mdAddr);
MDAPI const char* mdAddrGetInitializeErrorString(mdAddr);
MDAPI int         mdAddrSetLicenseString(mdAddr, const char*);
MDAPI const char* mdAddrGetBuildNumber(mdAddr);
MDAPI const char* mdAddrGetDatabaseDate(mdAddr);
MDAPI const char* mdAddrGetExpirationDate(mdAddr);
MDAPI const char* mdAddrGetLicenseExpirationDate(mdAddr);
MDAPI const char* mdAddrGetCanadianDatabaseDate(mdAddr);
MDAPI const char* mdAddrGetCanadianExpirationDate(mdAddr);
MDAPI void        mdAddrSetPathToUSFiles(mdAddr, const char*);
MDAPI void        mdAddrSetPathToCanadaFiles(mdAddr, const char*);
MDAPI void        mdAddrSetPathToDPVDataFiles(mdAddr, const char*);
MDAPI void        mdAddrSetPathToLACSLinkDataFiles(mdAddr, const char*);
MDAPI void        mdAddrSetPathToSuiteLinkDataFiles(mdAddr, const char*);
MDAPI void        mdAddrSetPathToSuiteFinderDataFiles(mdAddr, const char*);
MDAPI void        mdAddrSetPathToRBDIFiles(mdAddr, const char*);
MDAPI void        mdAddrSetCASSEnable(mdAddr, int);
MDAPI void        mdAddrSetUseUSPSPreferredCityNames(mdAddr, int);
MDAPI void        mdAddrSetDiacritics(mdAddr, enum mdDiacriticsMode);
MDAPI const char* mdAddrGetRBDIDatabaseDate(mdAddr);
MDAPI void        mdAddrClearProperties(mdAddr);

/* Errors and status */
MDAPI const char* mdAddrGetStatusCode(mdAddr);
MDAPI const char* mdAddrGetErrorCode(mdAddr);
MDAPI const char* mdAddrGetErrorString(mdAddr);
MDAPI const char* mdAddrGetResults(mdAddr);

/* CASS form 3553 methods */
MDAPI void        mdAddrSetPS3553_B1_ProcessorName(mdAddr, const char*);
MDAPI void        mdAddrSetPS3553_B4_ListName(mdAddr, const char*);
MDAPI void        mdAddrSetPS3553_D3_Name(mdAddr, const char*);
MDAPI void        mdAddrSetPS3553_D3_Company(mdAddr, const char*);
MDAPI void        mdAddrSetPS3553_D3_Address(mdAddr, const char*);
MDAPI void        mdAddrSetPS3553_D3_City(mdAddr, const char*);
MDAPI void        mdAddrSetPS3553_D3_State(mdAddr, const char*);
MDAPI void        mdAddrSetPS3553_D3_ZIP(mdAddr, const char*);
MDAPI const char* mdAddrGetFormPS3553(mdAddr);
MDAPI int         mdAddrSaveFormPS3553(mdAddr, const char*);
MDAPI void        mdAddrResetFormPS3553(mdAddr);
MDAPI void        mdAddrResetDPV(mdAddr);
MDAPI void        mdAddrSetStandardizationType(mdAddr, enum mdStandardizeMode);

/* main SOA Form methods */
MDAPI const char* mdAddrGetFormSOA(mdAddr);
MDAPI void        mdAddrSaveFormSOA(mdAddr, const char *);
MDAPI void        mdAddrResetFormSOA(mdAddr);
/* additional SOA */
MDAPI void        mdAddrSetSOACustomerInfo(mdAddr, const char *customerName,
			       const char * customerAddress);
MDAPI void        mdAddrSetSOACPCNumber(mdAddr, const char * CPCNumber);
MDAPI const char* mdAddrGetSOACustomerInfo(mdAddr);
MDAPI const char* mdAddrGetSOACPCNumber(mdAddr);
MDAPI long        mdAddrGetSOATotalRecords(mdAddr);
MDAPI float       mdAddrGetSOAAAPercentage(mdAddr);
MDAPI const char* mdAddrGetSOAAAExpiryDate(mdAddr);
MDAPI const char* mdAddrGetSOASoftwareInfo(mdAddr);
MDAPI const char* mdAddrGetSOAErrorString(mdAddr);

/* Required input */
MDAPI void        mdAddrSetCompany(mdAddr, const char*);
MDAPI void        mdAddrSetLastName(mdAddr, const char*);
MDAPI void        mdAddrSetAddress(mdAddr, const char*);
MDAPI void        mdAddrSetAddress2(mdAddr, const char*);
MDAPI void        mdAddrSetLastLine(mdAddr, const char*);
MDAPI void        mdAddrSetSuite(mdAddr, const char*);
MDAPI void        mdAddrSetCity(mdAddr, const char*);
MDAPI void        mdAddrSetState(mdAddr, const char*);
MDAPI void        mdAddrSetZip(mdAddr, const char*);
MDAPI void        mdAddrSetPlus4(mdAddr, const char*);
MDAPI void        mdAddrSetUrbanization(mdAddr, const char*);

/* Optional Input */
MDAPI void        mdAddrSetParsedAddressRange(mdAddr, const char*);
MDAPI void        mdAddrSetParsedPreDirection(mdAddr, const char*);
MDAPI void        mdAddrSetParsedStreetName(mdAddr, const char*);
MDAPI void        mdAddrSetParsedSuffix(mdAddr, const char*);
MDAPI void        mdAddrSetParsedPostDirection(mdAddr, const char*);
MDAPI void        mdAddrSetParsedSuiteName(mdAddr, const char*);
MDAPI void        mdAddrSetParsedSuiteRange(mdAddr, const char*);
MDAPI void        mdAddrSetParsedRouteService(mdAddr, const char*);         /* Canada only */
MDAPI void        mdAddrSetParsedLockBox(mdAddr, const char*);              /* Canada only */
MDAPI void        mdAddrSetParsedDeliveryInstallation(mdAddr, const char*); /* Canada only */

MDAPI void        mdAddrSetCountryCode(mdAddr, const char*);

/* Processing method */
MDAPI int         mdAddrVerifyAddress(mdAddr);

/* Output data */
MDAPI const char* mdAddrGetCompany(mdAddr);
MDAPI const char* mdAddrGetLastName(mdAddr);
MDAPI const char* mdAddrGetAddress(mdAddr);
MDAPI const char* mdAddrGetAddress2(mdAddr);
MDAPI const char* mdAddrGetSuite(mdAddr);
MDAPI const char* mdAddrGetCity(mdAddr);
MDAPI const char* mdAddrGetCityAbbreviation(mdAddr);
MDAPI const char* mdAddrGetState(mdAddr);
MDAPI const char* mdAddrGetZip(mdAddr);
MDAPI const char* mdAddrGetPlus4(mdAddr);
MDAPI const char* mdAddrGetCarrierRoute(mdAddr);
MDAPI const char* mdAddrGetDeliveryPointCode(mdAddr);
MDAPI const char* mdAddrGetDeliveryPointCheckDigit(mdAddr);
MDAPI const char* mdAddrGetCountyFips(mdAddr);
MDAPI const char* mdAddrGetCountyName(mdAddr);
MDAPI const char* mdAddrGetAddressTypeCode(mdAddr);
MDAPI const char* mdAddrGetAddressTypeString(mdAddr);
MDAPI const char* mdAddrGetUrbanization(mdAddr);
MDAPI const char* mdAddrGetCongressionalDistrict(mdAddr);
MDAPI const char* mdAddrGetLACS(mdAddr);
MDAPI const char* mdAddrGetLACSLinkIndicator(mdAddr);
MDAPI const char* mdAddrGetRBDI(mdAddr);
MDAPI const char* mdAddrGetPrivateMailbox(mdAddr);
MDAPI const char* mdAddrGetTimeZoneCode(mdAddr);
MDAPI const char* mdAddrGetTimeZone(mdAddr);
MDAPI const char* mdAddrGetMsa(mdAddr);
MDAPI const char* mdAddrGetPmsa(mdAddr);
MDAPI const char* mdAddrGetDefaultFlagIndicator(mdAddr);
MDAPI const char* mdAddrGetSuiteStatus(mdAddr);
MDAPI const char* mdAddrGetEWSFlag(mdAddr);
MDAPI const char* mdAddrGetCMRA(mdAddr);
MDAPI const char* mdAddrGetDsfNoStats(mdAddr);
MDAPI const char* mdAddrGetDsfVacant(mdAddr);
MDAPI const char* mdAddrGetCountryCode(mdAddr);
MDAPI const char* mdAddrGetZipType(mdAddr);
MDAPI const char* mdAddrGetFalseTable(mdAddr);
MDAPI const char* mdAddrGetDPVFootnotes(mdAddr);
MDAPI const char* mdAddrGetLACSLinkReturnCode(mdAddr);
MDAPI const char* mdAddrGetSuiteLinkReturnCode(mdAddr);
MDAPI const char* mdAddrGetELotNumber(mdAddr);
MDAPI const char* mdAddrGetELotOrder(mdAddr);
MDAPI const char* mdAddrGetAddressKey(mdAddr);
MDAPI int	mdAddrFindSuggestion(mdAddr);
MDAPI int	mdAddrFindSuggestionNext(mdAddr);

/* Form PS3553 fields */
MDAPI int         mdAddrGetPS3553_B6_TotalRecords(mdAddr);
MDAPI int         mdAddrGetPS3553_C1a_ZIP4Coded(mdAddr);
MDAPI int         mdAddrGetPS3553_C1c_DPBCAssigned(mdAddr);
MDAPI int         mdAddrGetPS3553_C1d_FiveDigitCoded(mdAddr);
MDAPI int         mdAddrGetPS3553_C1e_CRRTCoded(mdAddr);
MDAPI int         mdAddrGetPS3553_C1f_eLOTAssigned(mdAddr);
MDAPI int         mdAddrGetPS3553_E_HighRiseDefault(mdAddr);
MDAPI int         mdAddrGetPS3553_E_HighRiseExact(mdAddr);
MDAPI int         mdAddrGetPS3553_E_RuralRouteDefault(mdAddr);
MDAPI int         mdAddrGetPS3553_E_RuralRouteExact(mdAddr);
MDAPI int         mdAddrGetPS3553_E_LACSCount(mdAddr);
MDAPI int         mdAddrGetPS3553_E_EWSCount(mdAddr);
MDAPI int         mdAddrGetPS3553_E_DPVCount(mdAddr);

/* Future Form PS3553 fields */
MDAPI int         mdAddrGetPS3553_X_POBoxCount(mdAddr);
MDAPI int         mdAddrGetPS3553_X_HCExactCount(mdAddr);
MDAPI int         mdAddrGetPS3553_X_FirmCount(mdAddr);
MDAPI int         mdAddrGetPS3553_X_GenDeliveryCount(mdAddr);
MDAPI int         mdAddrGetPS3553_X_MilitaryZipCount(mdAddr);
MDAPI int         mdAddrGetPS3553_X_NonDeliveryCount(mdAddr);
MDAPI int         mdAddrGetPS3553_X_StreetCount(mdAddr);
MDAPI int         mdAddrGetPS3553_X_HCDefaultCount(mdAddr);
MDAPI int         mdAddrGetPS3553_X_OtherCount(mdAddr);
MDAPI int         mdAddrGetPS3553_X_LacsLinkCodeACount(mdAddr);
MDAPI int         mdAddrGetPS3553_X_LacsLinkCode00Count(mdAddr);
MDAPI int         mdAddrGetPS3553_X_LacsLinkCode14Count(mdAddr);
MDAPI int         mdAddrGetPS3553_X_LacsLinkCode92Count(mdAddr);
MDAPI int         mdAddrGetPS3553_X_LacsLinkCode09Count(mdAddr);
MDAPI int         mdAddrGetPS3553_X_SuiteLinkCodeACount(mdAddr);
MDAPI int         mdAddrGetPS3553_X_SuiteLinkCode00Count(mdAddr);



/* Parsed input data */
MDAPI const char* mdAddrGetParsedAddressRange(mdAddr);
MDAPI const char* mdAddrGetParsedPreDirection(mdAddr);
MDAPI const char* mdAddrGetParsedStreetName(mdAddr);
MDAPI const char* mdAddrGetParsedSuffix(mdAddr);
MDAPI const char* mdAddrGetParsedPostDirection(mdAddr);
MDAPI const char* mdAddrGetParsedSuiteName(mdAddr);
MDAPI const char* mdAddrGetParsedSuiteRange(mdAddr);
MDAPI const char* mdAddrGetParsedPrivateMailboxName(mdAddr);
MDAPI const char* mdAddrGetParsedPrivateMailboxNumber(mdAddr);
MDAPI const char* mdAddrGetParsedGarbage(mdAddr);
MDAPI const char* mdAddrGetParsedRouteService(mdAddr);         /* Canada only */
MDAPI const char* mdAddrGetParsedLockBox(mdAddr);              /* Canada only */
MDAPI const char* mdAddrGetParsedDeliveryInstallation(mdAddr); /* Canada only */

/* Reserved for Melissa DATA use */
MDAPI void        mdAddrSetReserved(mdAddr, const char*, const char*);
MDAPI const char* mdAddrGetReserved(mdAddr, const char*);
/*
 * Parse Interface
 */
typedef struct mdParse_ *mdParse;

MDAPI mdParse     mdParseCreate(void);
MDAPI void        mdParseDestroy(mdParse);

/* Setup methods */
MDAPI enum mdProgramStatus mdParseInitialize(mdParse,const char*);
MDAPI const char* mdParseGetBuildNumber(mdParse);

/* Processing method */
MDAPI void        mdParseParse(mdParse, const char*);
MDAPI void        mdParseParseCanadian(mdParse, const char*);
MDAPI int         mdParseParseNext(mdParse);
MDAPI void        mdParseLastLineParse(mdParse, const char*);

/* Output data */
MDAPI const char* mdParseGetZip(mdParse);
MDAPI const char* mdParseGetPlus4(mdParse);
MDAPI const char* mdParseGetCity(mdParse);
MDAPI const char* mdParseGetState(mdParse);
MDAPI const char* mdParseGetStreetName(mdParse);
MDAPI const char* mdParseGetRange(mdParse);
MDAPI const char* mdParseGetPreDirection(mdParse);
MDAPI const char* mdParseGetPostDirection(mdParse);
MDAPI const char* mdParseGetSuffix(mdParse);
MDAPI const char* mdParseGetSuiteName(mdParse);
MDAPI const char* mdParseGetSuiteNumber(mdParse);
MDAPI const char* mdParseGetPrivateMailboxNumber(mdParse);
MDAPI const char* mdParseGetPrivateMailboxName(mdParse);
MDAPI const char* mdParseGetGarbage(mdParse);
MDAPI const char* mdParseGetRouteService(mdParse);         /* Canada only */
MDAPI const char* mdParseGetGetLockBox(mdParse);           /* Canada only */
MDAPI const char* mdParseGetDeliveryInstallation(mdParse); /* Canada only */

/*
 * Street Data Interface
 */
typedef struct mdStreet_ *mdStreet;

MDAPI mdStreet    mdStreetCreate(void);
MDAPI void        mdStreetDestroy(mdStreet);

/* Setup methods */
MDAPI enum mdProgramStatus mdStreetInitialize(mdStreet, const char*, const char*, const char*);
MDAPI const char* mdStreetGetInitializeErrorString(mdStreet);
MDAPI const char* mdStreetGetDatabaseDate(mdStreet);
MDAPI const char* mdStreetGetBuildNumber(mdStreet);
MDAPI int         mdStreetSetLicenseString(mdStreet, const char*);
MDAPI const char* mdStreetGetLicenseExpirationDate(mdStreet);

/* Processing method */
MDAPI int         mdStreetFindStreet(mdStreet, const char*, const char*, int);
MDAPI int         mdStreetFindStreetNext(mdStreet);
MDAPI int         mdStreetIsAddressInRange(mdStreet, const char*, const char*, const char*);
MDAPI int         mdStreetIsAddressInRange2(mdStreet, const char*, const char*, const char*, const char*);

/* Output data */
MDAPI const char* mdStreetGetBaseAlternateIndicator(mdStreet);
MDAPI const char* mdStreetGetLACSIndicator(mdStreet);
MDAPI const char* mdStreetGetUrbanizationCode(mdStreet);
MDAPI const char* mdStreetGetUrbanizationName(mdStreet);
MDAPI const char* mdStreetGetLastLineNumber(mdStreet);
MDAPI const char* mdStreetGetAddressType(mdStreet);
MDAPI const char* mdStreetGetCongressionalDistrict(mdStreet);
MDAPI const char* mdStreetGetCountyFips(mdStreet);
MDAPI const char* mdStreetGetCarrierRoute(mdStreet);
MDAPI const char* mdStreetGetZip(mdStreet);
MDAPI const char* mdStreetGetDeliveryInstallation(mdStreet);
MDAPI const char* mdStreetGetPlus4High(mdStreet);
MDAPI const char* mdStreetGetPlus4Low(mdStreet);
MDAPI const char* mdStreetGetSuiteRangeOddEven(mdStreet);
MDAPI const char* mdStreetGetSuiteRangeHigh(mdStreet);
MDAPI const char* mdStreetGetSuiteRangeLow(mdStreet);
MDAPI const char* mdStreetGetSuiteName(mdStreet);
MDAPI const char* mdStreetGetPostDirection(mdStreet);
MDAPI const char* mdStreetGetSuffix(mdStreet);
MDAPI const char* mdStreetGetStreetName(mdStreet);
MDAPI const char* mdStreetGetPreDirection(mdStreet);
MDAPI const char* mdStreetGetPrimaryRangeOddEven(mdStreet);
MDAPI const char* mdStreetGetPrimaryRangeHigh(mdStreet);
MDAPI const char* mdStreetGetPrimaryRangeLow(mdStreet);
MDAPI const char* mdStreetGetCompany(mdStreet);

/*
 * Zip Code Data Interface
 */
typedef struct mdZip_ *mdZip;

MDAPI mdZip       mdZipCreate(void);
MDAPI void        mdZipDestroy(mdZip);

/* Setup methods */
MDAPI enum mdProgramStatus mdZipInitialize(mdZip, const char*, const char*, const char*);
MDAPI const char* mdZipGetInitializeErrorString(mdZip);
MDAPI const char* mdZipGetDatabaseDate(mdZip);
MDAPI const char* mdZipGetBuildNumber(mdZip);
MDAPI int         mdZipSetLicenseString(mdZip, const char*);
MDAPI const char* mdZipGetLicenseExpirationDate(mdZip);

/* Processing method */
MDAPI int         mdZipFindZip(mdZip, const char*, int);
MDAPI int         mdZipFindZipNext(mdZip);
MDAPI int         mdZipFindZipInCity(mdZip, const char*, const char*);
MDAPI int         mdZipFindZipInCityNext(mdZip);
MDAPI int         mdZipFindCityInState(mdZip, const char*, const char*);
MDAPI int         mdZipFindCityInStateNext(mdZip);
MDAPI double      mdZipComputeDistance(mdZip, double, double, double, double);
MDAPI double      mdZipComputeBearing(mdZip, double, double, double, double);

/* Output data */
MDAPI const char* mdZipGetCountyNameFromFips(mdZip, const char*);
MDAPI int         mdZipGetSCFArea(mdZip, const char*, float*, float*, float*, float*);
MDAPI const char* mdZipGetZip(mdZip);
MDAPI const char* mdZipGetCity(mdZip);
MDAPI const char* mdZipGetCityAbbreviation(mdZip);
MDAPI const char* mdZipGetState(mdZip);
MDAPI const char* mdZipGetZipType(mdZip);
MDAPI const char* mdZipGetCountyName(mdZip);
MDAPI const char* mdZipGetCountyFips(mdZip);
MDAPI const char* mdZipGetAreaCode(mdZip);
MDAPI const char* mdZipGetLongitude(mdZip);
MDAPI const char* mdZipGetLatitude(mdZip);
MDAPI const char* mdZipGetTimeZone(mdZip);
MDAPI const char* mdZipGetTimeZoneCode(mdZip);
MDAPI const char* mdZipGetMsa(mdZip);
MDAPI const char* mdZipGetPmsa(mdZip);
MDAPI const char* mdZipGetFacilityCode(mdZip);
MDAPI const char* mdZipGetLastLineIndicator(mdZip);
MDAPI const char* mdZipGetLastLineNumber(mdZip);
MDAPI const char* mdZipGetPreferredLastLineNumber(mdZip);
MDAPI const char* mdZipGetAutomation(mdZip);
MDAPI const char* mdZipGetFinanceNumber(mdZip);


#endif /* __cplusplus && (!MDCFORCE) */

#endif /* MDADDR_H */
