
extern zend_class_entry *phalcon_mvc_model_validator_exclusionin_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_Exclusionin);

PHP_METHOD(Phalcon_Mvc_Model_Validator_Exclusionin, validate);
static zend_object_value zephir_init_properties_Phalcon_Mvc_Model_Validator_Exclusionin(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_exclusionin_validate, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\EntityInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_validator_exclusionin_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Validator_Exclusionin, validate, arginfo_phalcon_mvc_model_validator_exclusionin_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
