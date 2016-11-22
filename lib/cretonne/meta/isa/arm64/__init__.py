"""
ARM 64-bit Architecture
-----------------------

ARMv8 CPUs running the Aarch64 architecture.
"""

from __future__ import absolute_import
from . import defs
from . import registers  # noqa

# Re-export the primary target ISA definition.
ISA = defs.ISA.finish()
