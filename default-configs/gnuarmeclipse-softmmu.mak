# Default configuration for gnuarmeclipse-softmmu

# No longer reuse the arm-softmmu configuration,
# define only what is needed.

CONFIG_ARM_GIC=y
CONFIG_ARM_GIC_KVM=$(CONFIG_KVM)
CONFIG_ARM_TIMER=y
CONFIG_ARM_MPTIMER=y
CONFIG_STELLARIS=y
CONFIG_STELLARIS_INPUT=y
CONFIG_STELLARIS_ENET=y
CONFIG_PTIMER=y
CONFIG_PCI=n

# [GNU ARM Eclipse]
CONFIG_STM32=y
CONFIG_KINETIS=n
CONFIG_LPC=n
CONFIG_TIVA=n
CONFIG_XMC=n
CONFIG_SAM=n
# [GNU ARM Eclipse]
