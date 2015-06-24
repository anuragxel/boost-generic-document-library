#ifndef _CELL_HPP
#define _CELL_HPP

//          Copyright Anurag Ghosh 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file ../../../../../LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <memory>
#include <boost/document/detail/cell_interface.hpp>

namespace boost {

	class cell {
	private:
		std::shared_ptr<cell_interface> pimpl_;
	public:

	explicit cell(const std::shared_ptr<cell_interface> impl) : pimpl_(impl) {
		
	}
	
    cell& operator=(const std::string& str) {
    	pimpl_->set_cell_value(str);
    	return *this;
    }

    cell& operator=(float i) {
    	pimpl_->set_cell_value(i);
       return *this;
    }
    
	~cell() {
	}

	};
} // namespace boost

#endif