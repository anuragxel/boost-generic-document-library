#ifndef _DOCUMENT_HPP
#define _DOCUMENT_HPP

//          Copyright Anurag Ghosh 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file ../../../../../LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/filesystem.hpp>
#include <boost/document/detail/document_exception.hpp>
#include <boost/document/detail/document_file_format.hpp>

namespace boost {

    /* \brief This is the main class interface to be 
     *        exposed to the library user.
     */
	class document {
	private:
		boost::filesystem::path file_path;
		bool is_file_opened;
	public:
		
		//! \brief Default Constructor.
		//!        Not preferred at all.
		document();
		
		//! \brief The de facto Constructor.
		//!        Creates a new document object.  
		document(const boost::filesystem::path path);
		
		//! \brief Destructor
		//!        Closes Unsaved Documents.
		~document();
		
		//! \brief Opens document using Calc/Excel given in
		//!        the file path.
		void open_document();


		//! \brief Opens document using Calc/Excel given in
		//!        the file path.
		void open_document(const boost::filesystem::path& path);
		
		//! \brief Closes document using Calc/Excel given in
		//!        the file path.
		void close_document();
		
		//! \brief Closes document using Calc/Excel given in
		//!        the file path.
		void close_document(const boost::filesystem::path& path);

		//! \brief saves document using Calc/Excel given in
		//!        the file path.
		void save_document();

		//! \brief Exports document using Calc/Excel given in
		//!        the file path and the file format. Default
		//!        format is PDF.
		void export_document(const boost::filesystem::path& path,boost::document_file_format::type format = document_file_format::PDF);

		//! \brief Exports document using Calc/Excel given in
		//!        the file path and the file format. Default
		//!        format is PDF.
		void export_document(boost::document_file_format::type format = document_file_format::PDF);
	};

} // namespace boost

#endif