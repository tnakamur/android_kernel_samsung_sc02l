# SPDX-License-Identifier: GPL-2.0
dtb-y += exynos/exynos7885-jackpotlte_jpn_dcm_00.dtb
dtb-y += exynos/exynos7885-jackpotlte_jpn_dcm_03.dtb

targets += dtbs
DTB_LIST  := $(dtb-y) $(dtbo-y)
always    := $(DTB_LIST)

dtbs: $(addprefix $(obj)/, $(DTB_LIST))

clean-files := *.dtb*
