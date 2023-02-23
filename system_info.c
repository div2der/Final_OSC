#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/cpu.h>
#include <linux/mm.h>

static int __init system_info_init(void)
{
    struct cpuinfo_x86 *c = &cpu_data(0);
        unsigned long total_ram_mem_gb = totalram_pages() * PAGE_SIZE / 1024;

    printk(KERN_INFO "RAM Memory: %lu GB\n", total_ram_mem_gb / (1024 * 1024));
    printk(KERN_INFO "CPU Model: %s\n", c->x86_model_id);
    return 0;
}

static void __exit system_info_exit(void)
{
    printk(KERN_INFO "System info module removed!\n");
}

module_init(system_info_init);
module_exit(system_info_exit);

MODULE_LICENSE("GPL");

MODULE_AUTHOR("Azamat, Ilya, Beybarys from CS-2117");
MODULE_DESCRIPTION("Prints system info(CPU and RAM)");

