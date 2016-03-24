from django.conf.urls import patterns, include, url
from django.contrib import admin
from finalapp.views import *

urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'final.views.home', name='home'),
    # url(r'^blog/', include('blog.urls')),

    url(r'^admin/', include(admin.site.urls)),
    url(r'^login/$', render_login_page),
    url(r'^user/(.*)',render_instruction_page),
    url(r'^questions/(.*)/(.*)',render_question_page),
    url(r'^refresh/',refresh_page),
    url(r'^final_score/(.*)',final_score),
    url(r'^timer/(.*)',timer_help)
)
