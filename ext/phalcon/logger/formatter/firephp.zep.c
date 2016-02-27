
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * Phalcon\Logger\Formatter\Firephp
 *
 * Formats messages so that they can be sent to FirePHP
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_Firephp) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Formatter, Firephp, phalcon, logger_formatter_firephp, phalcon_logger_formatter_ce, phalcon_logger_formatter_firephp_method_entry, 0);

	zend_declare_property_bool(phalcon_logger_formatter_firephp_ce, SL("_showBacktrace"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_logger_formatter_firephp_ce, SL("_enableLabels"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_logger_formatter_firephp_ce TSRMLS_CC, 1, phalcon_logger_formatterinterface_ce);
	return SUCCESS;

}

/**
 * Returns the string meaning of a logger constant
 */
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, getTypeString) {

	zval *type_param = NULL;
	int type;

	zephir_fetch_params(0, 1, 0, &type_param);

	type = zephir_get_intval(type_param);


	do {
		if (type == 0 || type == 1 || type == 3) {
			RETURN_STRING("ERROR", 1);
		}
		if (type == 2 || type == 4) {
			RETURN_STRING("WARN", 1);
		}
		if (type == 6 || type == 5 || type == 8) {
			RETURN_STRING("INFO", 1);
		}
		if (type == 7 || type == 9) {
			RETURN_STRING("LOG", 1);
		}
	} while(0);

	RETURN_STRING("CUSTOM", 1);

}

/**
 * Returns the string meaning of a logger constant
 */
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, setShowBacktrace) {

	zval *isShow_param = NULL;
	zend_bool isShow;

	zephir_fetch_params(0, 0, 1, &isShow_param);

	if (!isShow_param) {
		isShow = 0;
	} else {
		isShow = zephir_get_boolval(isShow_param);
	}


	if (isShow) {
		zephir_update_property_this(this_ptr, SL("_showBacktrace"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_showBacktrace"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Returns the string meaning of a logger constant
 */
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, getShowBacktrace) {

	

	RETURN_MEMBER(this_ptr, "_showBacktrace");

}

/**
 * Returns the string meaning of a logger constant
 */
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, enableLabels) {

	zval *isEnable_param = NULL;
	zend_bool isEnable;

	zephir_fetch_params(0, 0, 1, &isEnable_param);

	if (!isEnable_param) {
		isEnable = 0;
	} else {
		isEnable = zephir_get_boolval(isEnable_param);
	}


	if (isEnable) {
		zephir_update_property_this(this_ptr, SL("_enableLabels"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_enableLabels"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Returns the labels enabled
 */
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, labelsEnabled) {

	

	RETURN_MEMBER(this_ptr, "_enableLabels");

}

/**
 * Applies a format to a message before sending it to the log
 *
 * @param string $message
 * @param int $type
 * @param int $timestamp
 * @param array $context
 *
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, format) {

	HashTable *_11$$4;
	HashPosition _10$$4;
	zval *_22;
	zend_bool _15, _18, param$$4 = 0;
	int type, timestamp, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *type_param = NULL, *timestamp_param = NULL, *context = NULL, *meta = NULL, *body = NULL, *backtrace = NULL, *encoded = NULL, *len = NULL, *lastTrace = NULL, *_1 = NULL, *_2, *_3, *_13, *_14, *_16, *_17, *_19, *_0$$3 = NULL, *backtraceItem$$4 = NULL, *key$$4 = NULL, *_4$$4, _5$$4 = zval_used_for_init, _6$$4, *_7$$4 = NULL, **_12$$4, *_8$$6, *_9$$7, *_20$$12, *_21$$12;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &message_param, &type_param, &timestamp_param, &context);

	zephir_get_strval(message, message_param);
	type = zephir_get_intval(type_param);
	timestamp = zephir_get_intval(timestamp_param);
	if (!context) {
		context = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(context) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "interpolate", NULL, 0, message, context);
		zephir_check_call_status();
		zephir_get_strval(message, _0$$3);
	}
	ZEPHIR_INIT_VAR(meta);
	zephir_create_array(meta, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, type);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "gettypestring", NULL, 0, _2);
	zephir_check_call_status();
	zephir_array_update_string(&meta, SL("Type"), &_1, PH_COPY | PH_SEPARATE);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_showBacktrace"), PH_NOISY_CC);
	if (zephir_is_true(_3)) {
		param$$4 = 0;
		ZEPHIR_INIT_VAR(_4$$4);
		ZEPHIR_GET_CONSTANT(_4$$4, "PHP_VERSION");
		ZEPHIR_SINIT_VAR(_5$$4);
		ZVAL_STRING(&_5$$4, "5.3.6", 0);
		ZEPHIR_SINIT_VAR(_6$$4);
		ZVAL_STRING(&_6$$4, "<", 0);
		ZEPHIR_CALL_FUNCTION(&_7$$4, "version_compare", NULL, 241, _4$$4, &_5$$4, &_6$$4);
		zephir_check_call_status();
		if (!(zephir_is_true(_7$$4))) {
			param$$4 = (2) ? 1 : 0;
		}
		ZEPHIR_SINIT_NVAR(_5$$4);
		ZVAL_BOOL(&_5$$4, (param$$4 ? 1 : 0));
		ZEPHIR_CALL_FUNCTION(&backtrace, "debug_backtrace", NULL, 153, &_5$$4);
		zephir_check_call_status();
		ZEPHIR_MAKE_REF(backtrace);
		ZEPHIR_CALL_FUNCTION(&lastTrace, "end", NULL, 172, backtrace);
		ZEPHIR_UNREF(backtrace);
		zephir_check_call_status();
		if (zephir_array_isset_string(lastTrace, SS("file"))) {
			zephir_array_fetch_string(&_8$$6, lastTrace, SL("file"), PH_NOISY | PH_READONLY, "phalcon/logger/formatter/firephp.zep", 133 TSRMLS_CC);
			zephir_array_update_string(&meta, SL("File"), &_8$$6, PH_COPY | PH_SEPARATE);
		}
		if (zephir_array_isset_string(lastTrace, SS("line"))) {
			zephir_array_fetch_string(&_9$$7, lastTrace, SL("line"), PH_NOISY | PH_READONLY, "phalcon/logger/formatter/firephp.zep", 137 TSRMLS_CC);
			zephir_array_update_string(&meta, SL("Line"), &_9$$7, PH_COPY | PH_SEPARATE);
		}
		zephir_is_iterable(backtrace, &_11$$4, &_10$$4, 1, 0, "phalcon/logger/formatter/firephp.zep", 146);
		for (
		  ; zephir_hash_get_current_data_ex(_11$$4, (void**) &_12$$4, &_10$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_11$$4, &_10$$4)
		) {
			ZEPHIR_GET_HMKEY(key$$4, _11$$4, _10$$4);
			ZEPHIR_GET_HVALUE(backtraceItem$$4, _12$$4);
			zephir_array_unset_string(&backtraceItem$$4, SS("object"), PH_SEPARATE);
			zephir_array_unset_string(&backtraceItem$$4, SS("args"), PH_SEPARATE);
			zephir_array_update_zval(&backtrace, key$$4, &backtraceItem$$4, PH_COPY | PH_SEPARATE);
		}
		zend_hash_destroy(_11$$4);
		FREE_HASHTABLE(_11$$4);
	}
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("_enableLabels"), PH_NOISY_CC);
	if (zephir_is_true(_13)) {
		zephir_array_update_string(&meta, SL("Label"), &message, PH_COPY | PH_SEPARATE);
	}
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("_enableLabels"), PH_NOISY_CC);
	_15 = !zephir_is_true(_14);
	if (_15) {
		_16 = zephir_fetch_nproperty_this(this_ptr, SL("_showBacktrace"), PH_NOISY_CC);
		_15 = !zephir_is_true(_16);
	}
	_17 = zephir_fetch_nproperty_this(this_ptr, SL("_enableLabels"), PH_NOISY_CC);
	_18 = zephir_is_true(_17);
	if (_18) {
		_19 = zephir_fetch_nproperty_this(this_ptr, SL("_showBacktrace"), PH_NOISY_CC);
		_18 = !zephir_is_true(_19);
	}
	if (_15) {
		ZEPHIR_CPY_WRT(body, message);
	} else if (_18) {
		ZEPHIR_INIT_NVAR(body);
		ZVAL_STRING(body, "", 1);
	} else {
		ZEPHIR_INIT_NVAR(body);
		array_init(body);
		_20$$12 = zephir_fetch_nproperty_this(this_ptr, SL("_showBacktrace"), PH_NOISY_CC);
		if (zephir_is_true(_20$$12)) {
			zephir_array_update_string(&body, SL("backtrace"), &backtrace, PH_COPY | PH_SEPARATE);
		}
		_21$$12 = zephir_fetch_nproperty_this(this_ptr, SL("_enableLabels"), PH_NOISY_CC);
		if (!(zephir_is_true(_21$$12))) {
			zephir_array_update_string(&body, SL("message"), &message, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_VAR(_22);
	zephir_create_array(_22, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_22, meta);
	zephir_array_fast_append(_22, body);
	ZEPHIR_INIT_VAR(encoded);
	zephir_json_encode(encoded, &(encoded), _22, 0  TSRMLS_CC);
	ZEPHIR_INIT_VAR(len);
	ZVAL_LONG(len, zephir_fast_strlen_ev(encoded));
	ZEPHIR_CONCAT_VSVS(return_value, len, "|", encoded, "|");
	RETURN_MM();

}

