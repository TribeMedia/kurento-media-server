/*
 * MediaFactory.cpp - Kurento Media Server
 *
 * Copyright (C) 2013 Kurento
 * Contact: Miguel París Díaz <mparisdiaz@gmail.com>
 * Contact: José Antonio Santos Cadenas <santoscadenas@kurento.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "MediaFactory.hpp"
#include "MediaPlayer.hpp"
#include "MediaRecorder.hpp"
#include "Stream.hpp"

#include "DummyMixer.hpp"

#include <glibmm.h>

enum MixerType {
  DefaultMixerType = 0,
  DummyMixerType = 1
};

namespace kurento
{

MediaFactory::MediaFactory() : MediaObjectImpl()
{
//         conn = Glib::signal_timeout().connect_seconds(
//                 sigc::mem_fun(*this, &MediaSessionImpl::pingTimeout),
//                 g_mediaSession_constants.DEFAULT_TIMEOUT);
}

MediaFactory::~MediaFactory() throw()
{

}

std::shared_ptr<MediaPlayer>
MediaFactory::createMediaPlayer()
{
//TODO: complete
  return std::shared_ptr<MediaPlayer> (new MediaPlayer (*this) );
}

std::shared_ptr<MediaRecorder>
MediaFactory::createMediaRecorder()
{
//TODO: complete
  return std::shared_ptr<MediaRecorder> (new MediaRecorder (*this) );
}

std::shared_ptr<Stream>
MediaFactory::createStream()
{
//TODO: complete
  return std::shared_ptr<Stream> (new Stream (*this) );
}

std::shared_ptr<Mixer>
MediaFactory::createMixer (const int32_t mixerId)
{
  //TODO: complete
  switch (mixerId) {
  case DefaultMixerType:
    return std::shared_ptr<Mixer> (new Mixer (*this) );
  case DummyMixerType:
    return std::shared_ptr<Mixer> (new DummyMixer (*this) );
  default:
    MediaServerException  e = MediaServerException();
    e.__set_description (std::string ("Mixer type does not exist.") );
    throw e;
  }
}

} // kurento