#ifndef DEBUG_H
#define DEBUG_H


#include <iostream>
#include <string>
#include <fstream>

//!Debug Class
/*!Enables us to create a link between the engine and the game */
class Debug
{
public:
	//!MessageType enum class
	/*!Hold's different enumerations for different messages we might want to log */
	enum class MessageType : unsigned short {
		TYPE_NONE = 0,
		TYPE_FATAL_ERROR,
		TYPE_ERROR,
		TYPE_WARNING,
		TYPE_TRACE,
		TYPE_INFO
	};

	// Makes sure this class can not be copied or another instance can not be created
	Debug() = delete;
	Debug(const Debug&) = delete;
	Debug(Debug&&) = delete;
	Debug& operator=(const Debug&) = delete;
	Debug& operator=(Debug&&) = delete;

	//!OnCreate static function
	/*!Initializes any of the needed variables and creates a new text file*/
	static void OnCreate(const std::string& name_ = "EngineLog");


	//!Static SetSeverity setter
	/*!Set's the 'currentSev' variable to what is put inside the brackets*/
	static void SetSeverity(MessageType type_);

	//!Static Info Function
	/*!Calls the 'Log' function with the [INFO] tag*/
	static void Info(const std::string& message_, const std::string fileName_, const int line_);

	//!Static Trace Function
	/*!Calls the 'Log' function with the [TRACE] tag*/
	static void Trace(const std::string& message_, const std::string fileName_, const int line_);

	//!Static Warning Function
	/*!Calls the 'Log' function with the [WARNING] tag*/
	static void Warning(const std::string& message_, const std::string fileName_, const int line_);

	//!Static Error Function
	/*!Calls the 'Log' function with the [ERROR] tag*/
	static void Error(const std::string& message_, const std::string fileName_, const int line_);

	//!Static FatalError Function
	/*!Calls the 'Log' function with the [FATALERROR] tag*/
	static void FatalError(const std::string& message_, const std::string fileName_, const int line_);

private:

	//!Static Log Function
	/*!Performs some necessary checks and then writes the message too a file*/
	static void Log(const MessageType type_, const std::string message_, const std::string& fileName_, const int line_);

	//!Static Current Severity
	/*!Currently severity*/
	static MessageType currentSev;

	//!Static string outputName
	/*!The name of the file that will be written too*/
	static std::string outputName;
};

#endif
