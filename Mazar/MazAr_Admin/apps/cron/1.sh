#!/bin/sh

source /opt/rh/python27/enable
. /home/admin/virtualenv/django/bin/activate

cd /home/admin/apps/smsg_r
python manage.py release_unused_phones

