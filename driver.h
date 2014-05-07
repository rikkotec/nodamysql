/**
 * package: nodamysql
 * version:  0.0.1
 * author:  Richard B. Winters <a href="mailto:rik@mmogp.com">rik At MassivelyModified</a>
 * copyright: 2013-2014 Richard B. Winters
 * license: Apache, Version 2.0 <http://www.apache.org/licenses/LICENSE-2.0>
 */


#ifndef DRIVER_H
#define DRIVER_H


// INCLUDES
#include <node.h>


/**
 * MySQL C++ Connector Driver
 *
 * Allows one to work with MySQL using JavaScript in Node.js.  Works using the MySQL C++ Connector current
 * version.  This driver provides intuitive facilities for building and executing simple and advanced queries.
 *
 * @since 0.0.1
 */
class Driver : public node::ObjectWrap
{
	public:
		static void Init( v8::Handle<v8::Object> exports );

	private:
		explicit Driver( String::AsciiValue host = "localhost", String::AsciiValue port = "3306", String::AsciiValue db = "test", String::AsciiValue user = "test", String::AsciiValue password = "password" );
		~Driver();

		static v8::Handle<v8::Value> New( const v8::Arguments& args );
		static v8::Handle<v8::Value> Select( const v8::Arguments& args );
		static v8::Handle<v8::Value> Where( const v8::Arguments& args );
		static v8::Handle<v8::Value> Join( const v8::Arguments& args );
		static v8::Handle<v8::Value> Limit( const v8::Arguments& args );
		static v8::Handle<v8::Value> Order( const v8::Arguments& args );
		static v8::Handle<v8::Value> Execute( const v8::Arguments& args );
		String::AsciiValue host_;
		String::AsciiValue port_;
		String::AsciiValue db_;
		String::AsciiValue user_;
		String::AsciiValue password_;
		String::AsciiValue query_;
		Object phmap_;
};

#endif
