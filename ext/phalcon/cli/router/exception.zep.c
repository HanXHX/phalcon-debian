
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * Phalcon\Cli\Router\Exception
 *
 * Exceptions thrown in Phalcon\Cli\Router will use this class
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_Router_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cli\\Router, Exception, phalcon, cli_router_exception, phalcon_exception_ce, NULL, 0);

	return SUCCESS;

}

