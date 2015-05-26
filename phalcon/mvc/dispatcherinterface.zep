
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc;

/**
 * Phalcon\Mvc\DispatcherInterface
 *
 * Interface for Phalcon\Mvc\Dispatcher
 */
interface DispatcherInterface extends \Phalcon\DispatcherInterface
{

	/**
	 * Sets the default controller suffix
	 */
	public function setControllerSuffix(string! controllerSuffix);

	/**
	 * Sets the default controller name
	 */
	public function setDefaultController(string! controllerName);

	/**
	 * Sets the controller name to be dispatched
	 */
	public function setControllerName(string! controllerName);

	/**
	 * Gets last dispatched controller name
	 */
	public function getControllerName() -> string;

	/**
	 * Returns the lastest dispatched controller
	 */
	public function getLastController() -> <\Phalcon\Mvc\ControllerInterface>;

	/**
	 * Returns the active controller in the dispatcher
	 */
	public function getActiveController() -> <\Phalcon\Mvc\ControllerInterface>;

}
