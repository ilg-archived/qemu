# How to publish the GNU MCU Eclipse QEMU binaries?

## Update the Change log

Open the `CHANGELOG.txt` file from  
`gnu-mcu-eclipse/qemu-build.git` project git, and copy 
entries to the web git.

In the web git, add new entries to the 
[Change log](https://gnu-mcu-eclipse.github.io/qemu/change-log/) 
(`pages/qemu/change-log.md`), grouped by days.

Note: if you missed to update the `CHANGELOG.txt` before starting the build, 
edit the file and rerun the build, it should take only a few minutes to 
recreate the archives with the correct file.

## Edit the build script

Edit the `VERSION` file to refer to the actual release.

## Push the build script git

Push `gnu-mcu-eclipse/qemu-build.git` to GitHub.

Possibly push the helper project too.

## Build

Follow the instructions on the 
[build](https://github.com/gnu-mcu-eclipse/qemu-build/blob/master/README.md) 
page.

## Prepare a new blog post 

In the `gnu-mcu-eclipse.github.io-source.git` web git:

- add a new file to `_posts/qemu/releases`
- name the file like `2018-05-23-qemu-v2-8-0-3-20180523-released.md`
- name the post like: **GNU MCU Eclipse QEMU v2.8.0-3-20180523 released**.
- as `download_url` use the generic `https://github.com/gnu-mcu-eclipse/qemu/releases/` 
- update the `date:` field with the current date

If any, close [issues](https://github.com/gnu-mcu-eclipse/qemu/issues) 
on the way. Refer to them as:

- **[Issue:\[#1\]\(...\)]**.

## Update the SHA sums

Copy/paste the build report at the end of the post as:

```console
## Checksums
The SHA-256 hashes for the files are:

1e93a4fe2c661cace1b28fb633a9e7eb2c20f352b717205ac22cd338fcee101b ?
gnu-mcu-eclipse-qemu-2.8.0-3-20180523-0703-centos32.tgz

d4260a47b3322bce6d8d74feb2409b04c45f0b18a2958bb04ed2c802abf60793 ?
gnu-mcu-eclipse-qemu-2.8.0-3-20180523-0703-centos64.tgz

0a910c2548513cbbead6f4dd3366ccd72ecc1d75a6aee65e40fd92bdc1e5587e ?
gnu-mcu-eclipse-qemu-2.8.0-3-20180523-0703-macos.tgz

065bac74d9d70ae240167936f155abb43097e29b7a4d14c53e473e2d76aa7cb9 ?
gnu-mcu-eclipse-qemu-2.8.0-3-20180523-0703-win32.zip

7b90e76a0705e9c15fe80373f9028934f179b5c75ea3d2f60dc709adc280e021 ?
gnu-mcu-eclipse-qemu-2.8.0-3-20180523-0703-win64.zip
```

## Update the Web

- commit the `gnu-mcu-eclipse.github.io-source` project; use a message 
like **GNU MCU Eclipse QEMU v2.8.0-3 released**
- wait for the Travis build to complete; occasionally links to not work,
 and might need to restart the build.
- remember the post URL, since it must be updated in the release page

Note: initially the link to binaries points to the parent releases folder, 
otherwise Travis will complain and do not publish the site to 
`gnu-mcu-eclipse.github.io`.

## Create a new GitHub release

- go to the [GitHub Releases](https://github.com/gnu-mcu-eclipse/qemu/releases) page
- click **Draft a new release**
- name the tag like **v2.8.0-3-20180523** (mind the dash in the middle!)
- name the release like **GNU MCU Eclipse QEMU v2.8.0-3-20180523** 
(mind the dash and the space)
- as description
  - add a downloads badge like `[![Github Releases (by Release)](https://img.shields.io/github/downloads/gnu-mcu-eclipse/qemu/v2.8.0-3-20180523/total.svg)]()`; use empty URL for now
  - copy the first paragraph from the Web release page
- add a link to the Web page `[Continue reading »]()`; use an empty URL for now
- get URL from web and update the above links
- **attach binaries** and SHA (drag and drop from the archives folder will do it)
- click the **Publish Release** button

Note: at this moment the system should send a notification to all clients watching this project.

## Update the web link 

In the web git:

- `download_url: https://github.com/gnu-mcu-eclipse/qemu/releases/tag/v2.8.0-3-20180523`
- use something like `v2.8.0-3 update link` as message

## Create the xPack release

Follow the instructions on the 
[qemu-xpack](https://github.com/gnu-mcu-eclipse/qemu-xpack/blob/xpack/README.md#maintainer-info)
page.

## Update the release with xPack easy install

- copy the **Easy install** section from a previous release
- update release number

## Share on Facebook

- go to the new post and follow the Share link.
- DO NOT select **On your own Timeline**, but **On a Page you manage**
- select GNU MCU Eclipse
- posting as GNU MCU Eclipse
- click **Post to Facebook**
- check the post in the [Facebook page](https://www.facebook.com/gnu-mcu-eclipse)

