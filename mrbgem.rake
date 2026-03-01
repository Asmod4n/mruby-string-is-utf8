MRuby::Gem::Specification.new('mruby-string-is-utf8') do |spec|
  spec.license = 'Simplified BSD License'
  spec.author  = 'Hendrik Beskow'
  spec.summary = 'checks if a string is valid utf8'
  spec.cxx.flags << '-std=c++11'
  spec.version = "2.0.0"
end
