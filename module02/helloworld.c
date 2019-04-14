/*  
 *  To Test this simply run    insmod helloworld.ko  MyStringParam=blahblahblah
 *  And Look in  /var/log/syslog for the message.
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h>		/* Needed for the macros */
#include <linux/moduleparam.h>
#include <linux/stat.h>


// Boring Stuff
#define DRIVER_AUTHOR "Krash"
#define DRIVER_DESC   "Hello World Driver"


MODULE_LICENSE("GPL"); // set license as GPL
MODULE_AUTHOR(DRIVER_AUTHOR);	/* Who wrote this module? */
MODULE_DESCRIPTION(DRIVER_DESC);	/* What does this module do */

/*  
 *  This module uses /dev/testdevice.  The MODULE_SUPPORTED_DEVICE macro might
 *  be used in the future to help automatic configuration of modules, but is 
 *  currently unused other than for documentation purposes.
 */
MODULE_SUPPORTED_DEVICE("testdevice");
//End boring Stuff.


static char *MyStringParam = ""; // This wil be our param that is passed!
module_param(MyStringParam, charp, 0000);
MODULE_PARM_DESC(MyStringParam, "A character string");



int init_module(void)
{
	printk(KERN_INFO "ROOTKITDEV_DEBUG:  My Parameter %s 1.\n", MyStringParam);
	return 0; // if not 0 ; this means driver failed to load . 
}

void cleanup_module(void)
{
	printk(KERN_INFO "ROOTKITDEV_DEBUG: Program Ending 1.\n");
}



