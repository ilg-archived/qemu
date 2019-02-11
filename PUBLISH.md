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

## Create a new GitHub pre-release

- go to the [GitHub Releases](https://github.com/gnu-mcu-eclipse/qemu/releases) page
- click **Draft a new release**
- name the tag like **v2.8.0-3-20180523** (mind the dashes in the middle!)
- name the release like **GNU MCU Eclipse QEMU v2.8.0-3-20180523** 
(mind the dashes)
- as description
  - add a downloads badge like `[![Github Releases (by Release)](https://img.shields.io/github/downloads/gnu-mcu-eclipse/qemu/v2.8.0-3-20180523/total.svg)]()`; use empty URL for now
  - draft a short paragraph explaining what are the main changes
- **attach binaries** and SHA (drag and drop from the archives folder will do it)
- enable the pre-release button
- click the **Publish Release** button

Note: at this moment the system should send a notification to all clients watching this project.


## Prepare a new blog post 

In the `gnu-mcu-eclipse.github.io-source.git` web git:

- add a new file to `_posts/qemu/releases`
- name the file like `2018-05-23-qemu-v2-8-0-3-20180523-released.md`
- name the post like: **GNU MCU Eclipse QEMU v2.8.0-3-20180523 released**.
- as `download_url` use the tagged URL like `https://github.com/gnu-mcu-eclipse/qemu/releases/tag/v2.8.0-3-20180523/` 
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

## Create the xPack release

Follow the instructions on the 
[qemu-xpack](https://github.com/gnu-mcu-eclipse/qemu-xpack/blob/xpack/README.md#maintainer-info)
page.

## Create the final GitHub release

- go to the [GitHub Releases](https://github.com/gnu-mcu-eclipse/qemu/releases) page
- update the link behind the badge with the blog URL
- add a link to the Web page `[Continue reading »]()`; use an same blog URL
- copy/paste the **Easy install** section
- update the current release version
- copy/paste the **Download analytics** section
- update the current release version
- disable the pre-release button
- click the **Update Release** button

## Tag the build commit

In the [gnu-mcu-eclipse/qemu-build](https://github.com/gnu-mcu-eclipse/qemu-build)
project, add a tag with the current version, like `v2.8.0-3-20180523` (with *v*).

## Update the README.md

List the new release in the project README.md.

## Share on Facebook

- go to the new post and follow the Share link.
- DO NOT select **On your own Timeline**, but **On a Page you manage**
- select GNU MCU Eclipse
- posting as GNU MCU Eclipse
- click **Post to Facebook**
- check the post in the [Facebook page](https://www.facebook.com/gnu-mcu-eclipse)

## Share on Twitter

* go to the new post and follow the Tweet link
* copy the content to the clipboard
* DO NOT click the Tweet button here, it'll not use the right account
* in a separate browser windows, open [TweetDeck](https://tweetdeck.twitter.com/)
* using the `@gnu_mcu_eclipse` account, paste the content
* click the Tweet button
