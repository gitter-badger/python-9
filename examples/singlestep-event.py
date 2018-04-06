#!/usr/bin/env python3


import sys

from libvmi import Libvmi, INIT_DOMAINNAME, INIT_EVENTS
from libvmi.event import SingleStepEvent


def callback():
    pass


def main(args):
    if len(args) != 2:
        print('./singlestep-event.py <vm_name>')
        return 1

    vm_name = args[1]

    with Libvmi(vm_name, INIT_DOMAINNAME | INIT_EVENTS) as vmi:
        num_vcpus = vmi.get_num_vcpus()
        ss_event = SingleStepEvent(range(num_vcpus), 1, callback)
        vmi.register_event(ss_event)
        # listen
        while True:
            vmi.listen(500)


if __name__ == '__main__':
    ret = main(sys.argv)
    sys.exit(ret)
