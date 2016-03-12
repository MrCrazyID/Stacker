/**
 * @file AppInfo.h
 * @author Ingmar Delsink
 * @date 2 may 2014
 * @brief File containing the version of Stacker.
 * In this file the Major, Minor and Revison Version of Stacker is stored.
 */

#ifndef APPINFO_H
#define APPINFO_H

#define APPNAME "Stacker"                                               ///<Application name
#define MAJOR_VERSION "3"                                               ///<Application Major Version
#define MINOR_VERSION "3"                                               ///<Application Minor Version
#define REVISION_VERSION "8"                                            ///<Application Revision
#define VERSION MAJOR_VERSION "." MINOR_VERSION "." REVISION_VERSION    ///<Application full Version
#define APPNAME_VERSION APPNAME " v" VERSION                            ///<Application name with full version numbering

#endif // APPINFO_H
